function [errCode, toplevel] = petscOptionsSetValue(iname, value)
% Sets an option name-value pair in the options database, overriding
% whatever is already present.
%
%   errCode = petscOptionsSetValue(iname, value) sets the option
%   iname in the option database to a string value. The iname must start
%   with '-'. The strings must be null-terminated.
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscOptionsInsertString, petscOptionsHasName petscOptionsGetInt,
%      PetscOptionsGetReal, PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode OptionsSetValue(Mat opts,MatOption op,PetscBool flg)
% http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/Sys/PetscOptionsSetValue.html

%#codegen -args {coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    toplevel = nargout>1;
    if ~isempty(iname) && iname(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsSetValue:InputError', ...
            'Argument name must be a null-terminated string.')
    end
    if ~isempty(value) && value(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsSetValue:InputError', ...
            'Argument value must be a null-terminated string.')
    end
    
    errCode = coder.ceval('PetscOptionsSetValue', PETSC_NULL_OPTIONS, ...
        coder.rref(iname), coder.rref(value));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsSetValue returned error code %d\n', errCode)
    end
end

end
