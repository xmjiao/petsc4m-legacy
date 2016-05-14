function [value, found, errCode, toplevel] = petscOptionsGetReal(opts, pre, name)
% Gets the double precision value for a particular option in the database.
%
%   [value, found, errCode, toplevel] = petscOptionsGetReal(opts, pre, name)
%   obtains a real value in the data base. The flag found is PETSC_TRUE
%   if the attribute was found.
%
% SEE ALSO: petscOptionsInsertString, petscOptionsHasName, 
%           PetscOptionsGetInt, PetscOptionsGetString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsGetReal(PetscOptions options,const char pre[],const char name[],PetscReal *dvalue,PetscBool  *set)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsGetReal.html

%#codegen -args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    pre0 = [pre char(0)];
    name0 = [name char(0)];
    value = 0;
    b_flag = coder.opaque('PetscBool');
    
    errCode = coder.ceval('PetscOptionsGetReal', PetscOptions(opts), ...
        coder.rref(pre0), coder.rref(name0), coder.wref(value), coder.wref(b_flag));
    
    if nargout>1
        found = int32(0); %#ok<NASGU>
        found = coder.ceval('(int)', b_flag);
    end
    
    toplevel = nargout>3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsGetReal returned error code %d\n', errCode)
    end
end

end
