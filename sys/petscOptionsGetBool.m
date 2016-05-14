function [value, found, errCode, toplevel] = petscOptionsGetBool(opts, pre, name)
% Gets the integer value for a particular option in the database.
%
%   [value, found, errCode, toplevel] = petscOptionsGetBool(opts, pre, name)
%   obtains a Boolean value in the data base. The flag found is PETSC_TRUE
%   if the attribute was found. The strings must be null-terminated.
%
% SEE ALSO: petscOptionsInsertString, petscOptionsHasName,
%           PetscOptionsGetInt, PetscOptionsGetReal, PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsGetBool(PetscOptions options,const char pre[],
%        const char name[],PetscBook *ivalue,PetscBool  *found)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsGetBool.html

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>3;
    if ~isempty(pre) && pre(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsGetBool:InputError', ...
            'Argument prefix must be a null-terminated string.')
    end
    if ~isempty(name) && name(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsGetBool:InputError', ...
            'Argument name must be a null-terminated character string.')
    end
    
    b_value = coder.opaque('PetscBool');
    b_flag = coder.opaque('PetscBool');
    
    errCode = coder.ceval('PetscOptionsGetBool', PetscOptions(opts), ...
        coder.rref(pre), coder.rref(name), coder.wref(b_value), coder.wref(b_flag));
    
    value = int32(0); %#ok<NASGU>
    value = coder.ceval('(int)', b_value);
    
    if nargout>1
        found = int32(0); %#ok<NASGU>
        found = coder.ceval('(int)', b_flag);
    end
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsGetBool returned error code %d\n', errCode)
    end
end

end
