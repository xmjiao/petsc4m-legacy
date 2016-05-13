function [flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxit, varargin)
% Solves linear system.
%
% Syntax:
%    [flag, reslres, iter] = mptKSPSolve(ksp, b)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol, maxit)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol, maxit, x0)
%    [flag, reslres, iter] = mptKSPSolve(ksp, b, x, rtol, maxit, x0, resvec)
%
% Description:
%    mptKSPSolve(ksp, b) solves the linear system using the tolerances
%    that have been set previously by the user or by PETSc. The solution
%    overwrites b.
%
%    mptKSPSolve(ksp, b, x) solves the linear system and saves the solution
%    into x.
%
%    mptKSPSolve(ksp, b, x, rtol) solves with the given relative tolerance.
%
%    mptKSPSolve(ksp, b, x, rtol, maxit) solves with the given relative 
%    tolerances and maximum iteration count.
%
%    mptKSPSolve(ksp, b, rtol, maxit, x0) uses x0 as the initial guess
%
%    mptKSPSolve(ksp, b, rtol, maxit, x0, resvec) also computes the
%    residual vector.
%
% See also mptKSPSetup, mptKSPCleanup

%#codegen -args {PetscKSP, PetscVec, PetscVec, 0, int32(0)}
%#codegen mptKSPSolve_2args -args {PetscKSP, PetscVec}
%#codegen mptKSPSolve_3args -args {PetscKSP, PetscVec, PetscVec}
%#codegen mptKSPSolve_4args -args {PetscKSP, PetscVec, PetscVec, 0}
%#codegen mptKSPSolve_6args -args {PetscKSP, PetscVec, PetscVec, 0, int32(0), PetscVec}
%#codegen mptKSPSolve_7args -args {PetscKSP, PetscVec, PetscVec, 0, int32(0), PetscVec, PetscVec}


% Solve the linear system
if nargin==2
    petscKSPSolve(ksp, b);
    petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
else
    % Set tolerances
    if nargin<4; rtol = PETSC_DEFAULT; end
    if nargin<5; maxit = PETSC_DEFAULT; end
    petscKSPSetTolerances(ksp, rtol, maxit);
    
    % Process initial guess
    if ~isempty(varargin)
        petscVecCopy(varargin{1}, x);
        petscKSPSetInitialGuessNonzero(ksp, PETSC_TRUE);
    else
        petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
    end

    petscKSPSolve(ksp, b, x);
end

if nargout>0
    flag = petscKSPGetConvergedReason(ksp);
end
if nargout>1
    relres = petscKSPGetResidualNorm(ksp);
end
if nargout>2
    iter = petscKSPGetIterationNumber(ksp);
end

if nargin>6
    petscKSPBuildResidual(ksp, varargin{2});
end

end
