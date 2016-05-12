function [x,flag,relres,iter,toplevel] = mptKSPSolve(ksp, b, rtol, maxit, x, nzig)
% Solves linear system.
%
% Syntax:
%    [x, flag, reslres, iter] = mptKSPSolve(ksp, b)
%    [x, flag, reslres, iter] = mptKSPSolve(ksp, b, rtol)
%    [x, flag, reslres, iter] = mptKSPSolve(ksp, b, rtol, maxit)
%    [x, flag, reslres, iter] = mptKSPSolve(ksp, b, rtol, maxit, x)
%    [x, flag, reslres, iter] = mptKSPSolve(ksp, b, rtol, maxit, x, nzig)
%
% Description:
%    mptKSPSolve(ksp, b) solves the linear system using the tolerances
%    that have been set previously by the user or by PETSc.
%
%    mptKSPSolve(ksp, b, rtol) uses the given relative tolerances.
%
%    mptKSPSolve(ksp, b, rtol, maxit) uses the given relative tolerances
%    and maximum iteration count.
%
%    x = mptKSPSolve(ksp, b, rtol, maxit, x) uses the vector preallocated
%    in x to store the solution. x is reset to 0 before solving.
%
%    x = mptKSPSolve(ksp, b, rtol, maxit, x, true) uses the vector
%    preallocated in x for the solution, and uses its initial value
%    as the nonzero initial guesses.
%
% See also mptKSPSetup, mptKSPCleanup

%#codegen -args {PetscKSP, PetscVec, 0, int32(0), PetscVec, int32(0)}
%#codegen mptKSPSolve_2args -args {PetscKSP, PetscVec}
%#codegen mptKSPSolve_3args -args {PetscKSP, PetscVec, 0}
%#codegen mptKSPSolve_4args -args {PetscKSP, PetscVec, 0, int32(0)}
%#codegen mptKSPSolve_5args -args {PetscKSP, PetscVec, 0, int32(0), PetscVec}


% Set tolerances
if nargin==4
    petscKSPSetTolerances(ksp, rtol, maxit);
elseif nargin==3
    petscKSPSetTolerances(ksp, rtol);
end

% Process initial guess
if nargin<5
    if nargout>4
        [x, ~, toplevel] = petscVecDuplicate(b);
        t_x = PetscVec(x);
    else
        x = petscVecDuplicate(b);
        t_x = x;
    end
    petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
else
    t_x = PetscVec(x);
    toplevel = nargout>4;
end

if nargin>5 && nzig
    petscKSPSetInitialGuessNonzero(ksp, PETSC_TRUE);
else
    petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
end

% Solve the linear system
petscKSPSolve(ksp, b, t_x);

if nargout>1
    flag = petscKSPGetConvergedReason(ksp);
end
if nargout>2
    relres = petscKSPGetResidualNorm(ksp);
end
if nargout>3
    iter = petscKSPGetIterationNumber(ksp);
end
end
