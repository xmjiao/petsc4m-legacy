function [opts, errCode, toplevel] = petscOptionsDestroy(opts)
%Destroys an option database. 
%
%  [opts, errCode] = petscOptionsDestroy(opts)
%
%  SEE ALSO: petscOptionsCreate
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsDestroy(PetscOptions *options)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsDestroy.html

%Not supported. Skip compilation.
%#codegen 

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_opts = PetscOptions(opts);
    
    errCode = coder.ceval('PetscOptionsDestroy', coder.ref(t_opts));
    
    toplevel = nargout>2;
    opts = PetscOptions(t_opts, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsDestroy returned error code %d\n', errCode)
    end
end
end
