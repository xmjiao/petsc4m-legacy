function [str, found, errCode, toplevel] = petscOptionsGetString(opts, pre, name)
% Gets the string value for a particular option in the database. 
%
%   [str, found, errCode, toplevel] = petscOptionsGetString(opts, pre, name)
%   obtains a string in the data base. The flag found is PETSC_TRUE
%   if the attribute was found. The strings must be null-terminated.
%
% SEE ALSO: petscOptionsInsertString, petscOptionsHasName, 
%           PetscOptionsGetInt, PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsGetString(PetscOptions options,const char pre[],const char name[],char string[],size_t len,PetscBool  *set)

% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsGetString.html

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    toplevel = nargout>3;
    if ~isempty(pre) && pre(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsGetString:InputError', ...
            'Argument pre must be a null-terminated string.')
    end
    if ~isempty(name) && name(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscOptionsGetString:InputError', ...
            'Argument name must be a null-terminated character string.')
    end
    
    b_flag = coder.opaque('PetscBool');
    
    str0 = char(zeros(1, 21));
    errCode = coder.ceval('PetscOptionsGetString', PetscOptions(opts), ...
        coder.rref(pre), coder.rref(name), coder.wref(str0), int32(20), coder.wref(b_flag));

    found = int32(0); %#ok<NASGU>
    found = coder.ceval('(int)', b_flag);
    
    str = '';
    for i=1:21
        if str0(i)==0
            str = str0(1:i);
            break;
        end
    end
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsGetString returned error code %d\n', errCode)
    end
end

end
