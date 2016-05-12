function [errCode, toplevel] = petscPCSetUp(pc)
%Prepares for the use of a preconditioner. 
%
%  errCode = petscPCSetUp(pc)
%
%  SEE ALSO: petscPCCreate, petscPCSetOperators, petscPCApply, petscPCDestroy
%
% PETSc C interface:
%   PetscErrorCode PCSetUp(PC pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetUp.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    
    errCode = coder.ceval('PCSetUp', t_pc);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetUp returned error code %d\n', errCode)
    end
end
end
