function [errCode, toplevel] = petscOptionsSetReal(iname, value)
% Sets an option name-value pair in the options database, overriding
% whatever is already present.
%
%   errCode = petscOptionsSetReal(iname, value) sets the option
%   iname in the option database to the given real value. The iname must start
%   with '-', and must be null-terminated.
%
%   errCode(int) return code (0 indicates OK)
%
% This is a high-level wrapper for petscOptionsSetValue.
%
% SEE ALSO: petscOptionsSetInt, petscOptionsSetValue, petscOptionsGetReal

%#codegen -args {coder.typeof(char(0), [1,inf]), PetscScalar(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    toplevel = nargout>1;
    if ~isempty(iname) && iname(end) && (toplevel || m2c_debug)
        m2c_error('Petsc4m:petscOptionsSetReal:InputError', ...
            'Argument name must be a null-terminated string.')
    end
    
    str = m2c_num2str(value);
    errCode = coder.ceval('PetscOptionsSetValue', PETSC_NULL_OPTIONS, ...
        coder.rref(iname), coder.rref(str));
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsSetValue returned error code %d\n', errCode)
    end
end
end
