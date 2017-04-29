function [flag,relres,iter,reshis,time] = petscKSPDriver(ksp, b, x, rtol, maxits, x0)
% Solves linear system.
%
% Syntax:
%    petscKSPDriver(ksp, b)
%    petscKSPDriver(ksp, b, x)
%    petscKSPDriver(ksp, b, x, rtol)
%    petscKSPDriver(ksp, b, x, rtol, maxits)
%    petscKSPDriver(ksp, b, x, rtol, maxits, x0)
%
%    [flag, relres, iter, reshis, time] = petscKSPDriver(...) returns the flag
%       (KSPConvergedReason), relative residual, number of iterations, 
%    history of residual used in convergence test (typically preconditioned 
%    residual), and execution times.
%
% Description:
%    petscKSPDriver(ksp, b) solves the linear system using the tolerances
%    that have been set previously by the user. The solution overwrites b.
%
%    petscKSPDriver(ksp, b, x) solves the linear system and saves the solution
%    into x.
%
%    petscKSPDriver(ksp, b, x, rtol) solves with the given relative tolerance.
%
%    petscKSPDriver(ksp, b, x, rtol, maxits) solves with the given relative
%    tolerances and maximum iteration count.
%
%    petscKSPDriver(ksp, b, rtol, maxits, x0) uses x0 as the initial guess
%
% See also petscKSPSetup, petscKSPCleanup

% Compute norm of b before it is overwritten
bnrm = petscVecNorm(b, PETSC_NORM_2);
t_ksp = PetscKSP(ksp);

if nargout>4
    time = 0;
    comm = petscObjectGetComm(t_ksp);
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    t = mpi_Wtime();
end

if nargin<5 || maxits==0
    maxits = PETSC_DEFAULT;
end

% Solve the linear system
if nargin==2
    x = b;
    nonzeroGuess = PETSC_FALSE;
else
    % Set tolerances
    if nargin>=4
        if rtol==0
            rtol = double(PETSC_DEFAULT);
        end
        petscKSPSetTolerances(t_ksp, double(rtol), double(PETSC_DEFAULT), ...
            double(PETSC_DEFAULT), int32(maxits));
    end
    
    % Process initial guess
    nonzeroGuess = int32(nargin>=6 && ~petscIsNULL(x0));
    if nonzeroGuess
        petscVecCopy(x0, x);
    end
end

if nargout>3
    petscKSPSetResidualHistory(t_ksp, maxits, PETSC_TRUE);
end

petscKSPSetInitialGuessNonzero(t_ksp, nonzeroGuess);
petscKSPSolve(t_ksp, b, x);

if nargout>4
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    time = mpi_Wtime()-t;
end

flag = petscKSPGetConvergedReason(t_ksp);
res = petscKSPGetResidualNorm(t_ksp);
iter = petscKSPGetIterationNumber(t_ksp);
relres = res/bnrm;

[rtol, abstol, dtol, maxits] = petscKSPGetTolerances(t_ksp);

if flag < 0 || relres>rtol
    pc = petscKSPGetPC(t_ksp);
    switch petscKSPGetPCSide(t_ksp)
        case PETSC_PC_LEFT
            side = 'left';
        case PETSC_PC_RIGHT
            side = 'right';
        otherwise
            side = 'symmetric';
    end
    
    m2c_printf('### %s with %s as %s preconditioner stopped with flag %d.\n', ...
        petscKSPGetType(t_ksp), petscPCGetType(pc), side, flag);
    m2c_printf('### The relative residual was %g after %d iterations.\n', relres, iter);
    m2c_printf('### The relative and absolute tolerances were %g and %g.\n', rtol, abstol);
    m2c_printf('### The divergence and max-iter tolerances were %d and %g.\n', maxits, dtol);
    m2c_printf(['### For explanation of the flag, see http://www.mcs.anl.gov/petsc/' ...
        'petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n']);
end

if nargout>3
    % Obtain convergence history
    reshis = petscKSPGetResidualHistory(t_ksp);
end
end
