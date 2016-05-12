function [errCode, toplevel] = petscPCSetFromOptions(pc)
%Sets PC options from the options database. This routine must be called
%before PCSetUp() if the user is to be allowed to set the Krylov type.
%
%  errCode = petscPCSetFromOptions(pc)
%
%  SEE ALSO: petscPCCreate, petscPCSetOperators, petscPCSolve, petscPCDestroy
%
% PETSc C interface:
%   PetscErrorCode PCSetFromOptions(PC pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetFromOptions.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    
    errCode = coder.ceval('PCSetFromOptions', t_pc);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetFromOptions returned error code %d\n', errCode)
    end
end
end
