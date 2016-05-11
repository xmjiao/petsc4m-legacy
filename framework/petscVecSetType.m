function errCode = petscVecSetType(vec, type)
%Builds a vector, for a particular vector implementation.
%
%   errCode = petscVecSetType(vec, type)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscVecCreate, petscVecSetValues
%
% PETSc C interface:
%   PetscErrorCode  VecSetType(Vec vec, VecType matype)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetType.html

%#codegen -args {PetscVec, PetscVecType}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    t_type = PetscVecType(type);
    
    errCode = coder.ceval('VecSetType', t_vec, t_type);
    
    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecSetType returned error code %d\n', errCode)
    end
end

end
