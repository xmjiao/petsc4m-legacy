function errCode = petscMatSetOptionsPrefix(mat, in_str)
%Sets the prefix used for searching for all Mat options in the database.
%   errCode = petscMatSetOptionsPrefix(mat, in_str)
%
%   mat    - the Mat context
%   in_str - string that contains options separated by blanks
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: MatSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode MatSetOptionsPrefix(Mat A,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetOptionsPrefix.html

%#codegen -args {PetscMat, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    % null-terminate the string.
    str0 = [in_str char(0)];
    
    errCode = coder.ceval('MatSetOptionsPrefix', t_mat, coder.rref(str0));

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'MatSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
