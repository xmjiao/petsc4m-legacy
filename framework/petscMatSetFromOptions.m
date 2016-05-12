function [errCode, toplevel] = petscMatSetFromOptions(mat)
%Configures the matrix from the options database.
%
%   errCode = petscMatSetFromOptions(mat)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscMatCreate, petscMatSetOptionsPrefix
%
% PETSc C interface:
%   PetscErrorCode  MatSetFromOptions(Mat mat)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetFromOptions.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    errCode = coder.ceval('MatSetFromOptions', t_mat);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetFromOptions returned error code %d\n', errCode)
    end
end

end
