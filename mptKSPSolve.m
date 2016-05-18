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
%    that have been set previously by the user. The solution overwrites b.
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
    petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
    petscKSPSolve(ksp, b);
else
    % Set tolerances
    if nargin>=4
        if nargin<5; maxit = PETSC_DEFAULT; end
        petscKSPSetTolerances(ksp, double(rtol), int32(maxit));
    end
    
    % Process initial guess
    if ~isempty(varargin) && ~petscIsNULL(varargin{1})
        petscVecCopy(varargin{1}, x);
        petscKSPSetInitialGuessNonzero(ksp, PETSC_TRUE);
    else
        petscKSPSetInitialGuessNonzero(ksp, PETSC_FALSE);
    end
    
    petscKSPSolve(ksp, b, x);
end

flag = petscKSPGetConvergedReason(ksp);
relres = petscKSPGetResidualNorm(ksp);
iter = petscKSPGetIterationNumber(ksp);

if nargin<4 || rtol < 0;
    rtol = petscOptionsGetReal(PETSC_NULL_OPTIONS, '', ['-ksp-rtol', char(0)]);
end
if nargin<5 || maxit < 0;
    maxit = petscOptionsGetInt(PETSC_NULL_OPTIONS, '', ['-ksp_max_it', char(0)]);
end

if relres>rtol
    pc = petscKSPGetPC(ksp);
    
    m2c_printf('### %s with %s stopped with relative residual %g after %d iterations.\n', ...
        petscKSPGetType(ksp), petscPCGetType(pc), relres, iter);
    m2c_printf('The relative convergence tolerance was %g. The max-iter was %d.\n', rtol, maxit);
    m2c_printf(['The return flag was %d. See http://www.mcs.anl.gov/petsc/' ...
        'petsc-current/docs/manualpages/KSP/KSPConvergedReason.html for explanations of the flag.\n'], flag);
end

if nargin>6 && ~petscIsNULL(varargin{2})
    petscKSPBuildResidual(ksp, varargin{2});
end

end
