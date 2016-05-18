function [errCode, toplevel] = petscPCFactorSetUpMatSolverPackage(pc)
%Can be called after petscKSPSetOperators() or petscPCSetOperators(),
% causes MatGetFactor() to be called so then one may set the options
% for that particular factorization object.
%
%  errCode = petscPCFactorSetUpMatSolverPackage(pc)
%
% Notes: After you have called this function (which has to be after
% the KSPSetOperators or PCSetOperators) you can call PCFactorGetMatrix
% and then set factor options on that matrix.
%
%  SEE ALSO: petscPCFactorSetMatSolverPackage, petscPCFactorGetMatrix
%
% PETSc C interface:
%   PetscErrorCode PCFactorSetUpMatSolverPackage(PC pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCFactorSetUpMatSolverPackage.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    
    errCode = coder.ceval('PCFactorSetUpMatSolverPackage', t_pc);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCFactorSetUpMatSolverPackage returned error code %d\n', errCode)
    end
end
end
