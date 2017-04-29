function [errCode, toplevel] = petscMatSetOptionsPrefix(mat, prefix)
%Sets the prefix used for searching for all Mat options in the database.
%   errCode = petscMatSetOptionsPrefix(mat, prefix)
%
%   mat    - the Mat context
%   prefix - the prefix string to prepend to all Mat option requests.
%            It must be null-terminated.
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscMatSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode MatSetOptionsPrefix(Mat A,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetOptionsPrefix.html

%#codegen -args {PetscMat, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('Petsc4m:petscMatSetOptionsPrefix:InputError', ...
            'The 2nd argument must be a null-terminated string.')
    end

    errCode = coder.ceval('MatSetOptionsPrefix', t_mat, coder.rref(prefix));
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
