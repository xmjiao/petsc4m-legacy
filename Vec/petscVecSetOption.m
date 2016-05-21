function [errCode, toplevel] = petscVecSetOption(vec, op, flg)
%Sets an option for controling a vector's behavior.
%
%   errCode = petscVecSetOption(vec, op, flg)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscVecSetValues, petscVecAssemblyBegin, petscVecAssemblyEnd
%
% PETSc C interface:
%   PetscErrorCode VecSetOption(Vec vec,VecOption op,PetscBool flg)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetOption.html

%#codegen -args {PetscVec, int32(0), int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);
    errCode = coder.ceval('VecSetOption', t_vec, op, flg);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetOptions returned error code %d\n', errCode)
    end
end

end
