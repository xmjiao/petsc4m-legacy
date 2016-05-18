function [flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxits, x0)
% Solves linear system.
%
% Syntax:
%    [flag, reslres, iter] = mptKSPSolve(ksp, b)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol, maxits)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol, maxits, x0)
%
% Description:
%    mptKSPSolve(ksp, b) solves the linear system using the tolerances
%    that have been set previously by the user. The solution overwrites b.
%
%    mptKSPSolve(ksp, b, x) solves the linear system and saves the solution
%    into x.
%
%    mptKSPSolve(ksp, b, x, rtol) solves with the given relative tolerance.
%
%    mptKSPSolve(ksp, b, x, rtol, maxits) solves with the given relative
%    tolerances and maximum iteration count.
%
%    mptKSPSolve(ksp, b, rtol, maxits, x0) uses x0 as the initial guess
%
% See also mptKSPSetup, mptKSPCleanup

%#codegen -args {PetscKSP, PetscVec, PetscVec, 0, int32(0), PetscVec}
%#codegen mptKSPSolve_2args -args {PetscKSP, PetscVec}
%#codegen mptKSPSolve_3args -args {PetscKSP, PetscVec, PetscVec}
%#codegen mptKSPSolve_4args -args {PetscKSP, PetscVec, PetscVec, 0}
%#codegen mptKSPSolve_5args -args {PetscKSP, PetscVec, PetscVec, 0, int32(0)}

% Solve the linear system
if nargin==2
    petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
    petscKSPSolve(ksp, b);
else
    % Set tolerances
    if nargin>=4
        if rtol==0
            rtol = double(PETSC_DEFAULT);
        end
        if nargin<5 || maxits==0
            maxits = PETSC_DEFAULT;
        end
        petscKSPSetTolerances(ksp, double(rtol), double(PETSC_DEFAULT), ...
            double(PETSC_DEFAULT), int32(maxits));
    end
    
    % Process initial guess
    if nargin>=6 && ~petscIsNULL(x0)
        petscVecCopy(x0, x);
        petscKSPSetInitialGuessNonzero(ksp, PETSC_TRUE);
    else
        petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
    end
    
    petscKSPSolve(ksp, b, x);
end

flag = petscKSPGetConvergedReason(ksp);
relres = petscKSPGetResidualNorm(ksp);
iter = petscKSPGetIterationNumber(ksp);
[rtol, abstol, dtol, maxits] = petscKSPGetTolerances(ksp);

if flag < 0 || relres>rtol
    pc = petscKSPGetPC(ksp);
    
    m2c_printf('### %s with %s preconditioner stopped with flag %d.\n', petscKSPGetType(ksp), petscPCGetType(pc), flag);
    m2c_printf('### The relative residual was %g after %d iterations.\n', relres, iter);
    m2c_printf('### The relative and absolute tolerances were %g and %g.\n', rtol, abstol);
    m2c_printf('### The divergence and max-iter tolerances were %d and %g.\n', maxits, dtol);
    m2c_printf(['### For explanation of the flag, see http://www.mcs.anl.gov/petsc/' ...
        'petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n']);
end

end
