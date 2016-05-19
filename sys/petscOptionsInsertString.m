function [errCode, toplevel] = petscOptionsInsertString(in_str)
%Inserts options into the database from a string
%   errCode = petscOptionsInsertString(in_str)
%
%   in_str -string that contains options separated by blanks and
%           must be null-terminated
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscOptionsInsertFile
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsInsertString(PetscOptions options,const char in_str[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsInsertString.html

%#codegen -args {coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>1;
    if ~isempty(in_str) && in_str(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsInsertString:InputError', ...
            'The argument must be a null-terminated string.')
    end

    errCode = coder.ceval('PetscOptionsInsertString', PETSC_NULL_OPTIONS, coder.rref(in_str));

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsInsertString returned error code %d\n', errCode)
    end
end

end
