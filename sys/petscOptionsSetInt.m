function [errCode, toplevel] = petscOptionsSetInt(opts, iname, value)
% Sets an option name-value pair into the options database, overriding
% whatever is already present.
%
%   errCode = petscOptionsSetInt(opts, iname, value) sets the option
%   iname in the option database to a given integer value. The iname must start
%   with '-', and must be null-terminated.
%
%   errCode(int) return code (0 indicates OK)
%
% This is a high-level wrapper for petscOptionsSetValue.
%
% SEE ALSO: petscOptionsSetReal, petscOptionsSetValue


%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>1;
    if ~isempty(iname) && iname(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsSetInt:InputError', ...
            'Argument name must be a null-terminated string.')
    end
    
    str = coder.nullcopy(zeros(20, 1, 'int8'));
    
    ptr = coder.opaque('char *'); %#ok<NASGU>
    ptr = coder.ceval('(char *)', coder.wref(str));
    
    coder.ceval('sprintf', ptr, ...
        coder.opaque('const char *', '"%d"'), int32(value));
    errCode = coder.ceval('PetscOptionsSetValue', PetscOptions(opts), ...
        coder.rref(iname), ptr);
    str = refv(str); %#ok<NASGU>
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsSetValue returned error code %d\n', errCode)
    end
end
end

