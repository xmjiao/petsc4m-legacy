function [errCode, toplevel] = petscPCFactorSetMatSolverPackage(pc, solver)
%Sets the software that is used to perform the factorization
%
%  errCode = petscpetscPCFactorSetMatSolverPackage(pc, solver) sets the
%       the solver to the given solver
%
%  SEE ALSO:  PetscpetscPCFactorSetMatSolverPackage, petscPCCreate
%
% PETSc C interface:
%   PetscErrorCode  PCFactorSetMatSolverPackage(PC pc,const MatSolverPackage ssolver)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/petscPCFactorSetMatSolverPackage.html

%#codegen -args {PetscPC, PetscMatSolverPackage}

errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('PCFactorSetMatSolverPackage', ...
        PetscPC(pc), coder.rref(solver));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscPCFactorSetMatSolverPackage returned error code %d\n', errCode)
    end
end
end
