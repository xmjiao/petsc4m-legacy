function [opts, errCode, toplevel] = petscOptionsCreate
%Creates an empty options database.
%
%  [opts, errCode] = petscOptionsCreate() creates an empty option database.
%
%  SEE ALSO: petscOptionsDestroy
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsCreate(PetscOptions *options)
% http://www.mcs.anl.gov/petsc/petsc-dev/docs/manualpages/Sys/PetscOptionsCreate.html

%Not supported. Skip compilation.
errCode = int32(-1);

if ~isempty(coder.target)
    t_opts = coder.opaque('PetscOptions');
    
    errCode = coder.ceval('PetscOptionsCreate', coder.wref(t_opts));
    
    toplevel = nargout>2;
    opts = PetscOptions(t_opts, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsCreate returned error code %d\n', errCode)
    end
end
end
