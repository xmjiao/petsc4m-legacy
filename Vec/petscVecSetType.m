function [errCode, toplevel] = petscVecSetType(vec, type)
%Builds a vector for a particular vector implementation.
%
%   errCode = petscVecSetType(vec, type)
%   The vector is PETSC_VECSEQ, PETSC_VECMPI, or PETSC_VECSHARED, etc.
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscVecCreate, petscVecSetValues
%
% PETSc C interface:
%   PetscErrorCode  VecSetType(Vec vec, VecType matype)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetType.html

%#codegen -args {PetscVec, PetscVecType}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);

    if ischar(type)
        errCode = coder.ceval('VecSetType', t_vec, coder.rref(type));
    else % If type is an opaque object of VecType, do not pass by reference.
        errCode = coder.ceval('VecSetType', t_vec, type);
    end

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetType returned error code %d\n', errCode)
    end
end

end
