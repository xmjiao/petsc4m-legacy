function [found, errCode, toplevel] = petscOptionsHasName(options, pre, name)
% Determines whether a certain option is given in the database. 
% This returns true whether the option is a number, string or boolean, 
% even its value is set to false.
%
%   [found, errCode, toplevel] = petscOptionsHasName(options, pre, name)
%   Set options to [] for default global database. The arguments
%   pre and name must be null-terminated.
%
% SEE ALSO: petscOptionsInsertString, PetscOptionsGetInt, petscOptionsGetReal, 
%           PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsHasName(PetscOptions options,const char pre[],const char name[],PetscBool  *set)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsHasName.html

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>2;
    if ~isempty(pre) && pre(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsHasName:InputError', ...
            'Argument pre must be a null-terminated string.')
    end
    if ~isempty(name) && name(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsHasName:InputError', ...
            'Argument name must be a null-terminated string.')
    end

    b_flag = coder.opaque('PetscBool');
    
    errCode = coder.ceval('PetscOptionsHasName', PetscOptions(options), ...
        coder.rref(pre), coder.rref(name), coder.wref(b_flag));
    
    if nargout>1
        found = int32(0); %#ok<NASGU>
        found = coder.ceval('(int)', b_flag);
    end
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsHasName returned error code %d\n', errCode)
    end
end

end
