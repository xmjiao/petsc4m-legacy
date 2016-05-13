function [errCode, toplevel] = petscOptionsSetValue(opts, iname, value)
% Sets an option name-value pair in the options database, overriding
% whatever is already present.
%
%   errCode = petscOptionsSetValue(opts, iname, value) sets the option
%   iname in the option database to a string value. The iname must start
%   with '-'. The strings iname and value do not need to be null-terminated.
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscOptionsInsertString, petscOptionsHasName petscOptionsGetInt, 
%      PetscOptionsGetReal, PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode OptionsSetValue(Mat opts,MatOption op,PetscBool flg)
% http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/Sys/PetscOptionsSetValue.html

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    iname0 = [iname char(0)];
    value0 = [value char(0)];
    errCode = coder.ceval('PetscOptionsSetValue', PetscOptions(opts), ...
        coder.rref(iname0), coder.rref(value0));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsSetValue returned error code %d\n', errCode)
    end
end

end
