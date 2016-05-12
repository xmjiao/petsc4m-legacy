function [errCode, toplevel] = petscKSPSetOperators(ksp, Amat, Pmat)
%Sets the matrix associated with the linear system and a (possibly)
%different one associated with the preconditioner.
%
%  errCode = petscKSPSetOperators(ksp, Amat)
%
%  sets the matrix to be Amat and use the same matrix to construct the
%  preconditioner.
%     ksp - iterative context obtained from petscKSPCreate
%     Amat	  - the right hand side vector
%
%  errCode = petscKSPSetOperators(ksp, Amat, Pmat)
%
%  uses the matrix Pmat to construct the preconditioner.
%
%  SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy
%
% PETSc C interface:
%   PetscErrorCode  KSPSetOperators(KSP ksp,Mat Amat,Mat Pmat)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOperators.html

%#codegen -args {PetscKSP, PetscMat, PetscMat}
%#codegen petscKSPSetOperators_AforP -args {PetscKSP, PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    t_Amat = PetscMat(Amat);
    
    if nargin==2
        t_Pmat = t_Amat;
    else
        t_Pmat = PetscMat(Pmat);
    end
    
    errCode = coder.ceval('KSPSetOperators', t_ksp, t_Amat, t_Pmat);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetOperators returned error code %d\n', errCode)
    end
end
end
