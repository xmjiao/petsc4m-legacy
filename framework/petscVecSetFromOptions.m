function [errCode, toplevel] = petscVecSetFromOptions(vec)
%Configures the vector from the options database.
%
%   errCode = petscVecSetFromOptions(vec)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscVecCreate, petscVecSetOptionsPrefix
%
% PETSc C interface:
%   PetscErrorCode  VecSetFromOptions(Vec vec)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetFromOptions.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    errCode = coder.ceval('VecSetFromOptions', t_vec);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetFromOptions returned error code %d\n', errCode)
    end
end

end
