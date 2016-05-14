function [errCode, toplevel] = petscOptionsSetReal(opts, iname, value)
% Sets an option name-value pair in the options database, overriding
% whatever is already present.
%
%   errCode = petscOptionsSetReal(opts, iname, value) sets the option
%   iname in the option database to the given real value. The iname must start
%   with '-', and must be null-terminated.
%
%   errCode(int) return code (0 indicates OK)
%
% This is a high-level wrapper for petscOptionsSetValue.
%
% SEE ALSO: petscOptionsSetInt, petscOptionsSetValue, petscOptionsGetReal

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), 0}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>1;
    if ~isempty(iname) && iname(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsSetReal:InputError', ...
            'Argument name must be a null-terminated string.')
    end
    
    str = coder.nullcopy(zeros(40, 1, 'int8'));
    
    ptr = coder.opaque('char *'); %#ok<NASGU>
    ptr = coder.ceval('(char *)', coder.wref(str));
    
    coder.ceval('sprintf', ptr, ...
        coder.opaque('const char *', '"%.17g"'), double(value));
    errCode = coder.ceval('PetscOptionsSetValue', PetscOptions(opts), ...
        coder.rref(iname), ptr);
    str = refv(str); %#ok<NASGU>
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsSetValue returned error code %d\n', errCode)
    end
end
end
