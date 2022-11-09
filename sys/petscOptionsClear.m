function [opts, errCode, toplevel] = petscOptionsClear(opts)
%Destroys an option database. 
%
%  [opts, errCode] = petscOptionsClear(opts)
%
%  SEE ALSO: petscOptionsCreate
%
% PETSc C interface:
%   PetscErrorCode  petscOptionsClear(PetscOptions *options)
% https://petsc.org/release/docs/manualpages/Sys/PetscOptionsClear

errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('petsc4m.h');
    if nargin == 0
        opts = PETSC_NULL_OPTIONS;
    end
    t_opts = PetscOptions(opts);
    
    errCode = coder.ceval('PetscOptionsClear', coder.ref(t_opts));
    
    toplevel = nargout>2;
    opts = PetscOptions(t_opts, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscOptionsClear returned error code %d\n', errCode)
    end
end
end
