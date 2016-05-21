function [errCode, toplevel] = petscKSPSetInitialGuessNonzero(ksp, flag)
%Tells the iterative solver that the initial guess is nonzero; otherwise 
%KSP assumes the initial guess is to be zero (and thus zeros it out before solving).
%
%  errCode = petscKSPSetInitialGuessNonzero(ksp, flag)
%  indicates the initial guess is non-zero if flag is PETSC_TRUE, and
%  is zeo if flag is PETSC_FALSE (0).
%
%  SEE ALSO: petscKSPGetInitialGuessNonzero
%
% PETSc C interface:
%   PetscErrorCode  KSPSetInitialGuessNonzero(KSP ksp,PetscBool flg)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetInitialGuessNonzero.html

%#codegen -args {PetscKSP, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    
    errCode = coder.ceval('KSPSetInitialGuessNonzero', t_ksp, flag);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetInitialGuessNonzero returned error code %d\n', errCode)
    end
end
end
