function [flag, errCode, toplevel] = petscKSPGetInitialGuessNonzero(ksp)
%Determines whether the KSP solver is using a zero initial guess.
%
%  [flag, errCode] = petscKSPGetInitialGuessNonzero(ksp) returns PETSC_TRUE
%  if guess is nonzero; otherwise, it returns PETSC_FALSE (0).
%
%  SEE ALSO: petscKSPSetInitialGuessNonzero
%
% PETSc C interface:
%   PetscErrorCode  KSPGetInitialGuessNonzero(KSP ksp,PetscBool *flg)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetInitialGuessNonzero.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    t_flag = coder.opaque('PetscBool');
    errCode = coder.ceval('KSPGetInitialGuessNonzero', t_ksp, coder.wref(t_flag));
    
    flag = int32(0); %#ok<NASGU>
    flag = coder.ceval(' ', t_flag);
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetInitialGuessNonzero returned error code %d\n', errCode)
    end
end
end
