function [x, flag, relres, iter, reshis, times] = petscSolve(varargin)
% Solves a linear system using any PETSc solver for matrix in sparse format.
%
% Syntax:
%    petscSolve(A, b)
%    petscSolve(A, b, solver)
%    petscSolve(A, b, solver, rtol)
%    petscSolve(A, b, solver, rtol, maxit)
%    petscSolve(A, b, solver, rtol, maxit, pctype)
%    petscSolve(A, b, solver, rtol, maxit, pctype, pcopt)
%    petscSolve(A, b, solver, rtol, maxit, pctype, pcopt, x0)
%    petscSolve(A, b, solver, rtol, maxit, pctype, pcopt, x0, opts)
%
%    [x, flag, relres, iter, reshis, times] = petscSolve(A, b, ...)
%    returns the solution vector x, the flag (KSPConvergedReason), relative
%    residual, number of iterations, history of residual used in convergence
%    test (typically preconditioned residual), and the execution times in
%    setup and solve.
%
%    A is a sparse matrix in sparse format. b, x and resvec are all regular
%    vectors. Solver is a value of PETSC_KSP*. pctype is a value of
%    PETSC_PC*, and pcopt is a value of PETSC_MATSOLVER*.
%
%    For rtol, maxit, use 0 to use default values.
%    For solver, pctype, pcopt and opts, use empty string ('') to use default.
%    For x0, use zeros(0, 1) to disable initial guess.
%
%    When times is given, it returns a 2-vector contaning the times spent
%    in setup and in solve separately.
%
% Description:
%    petscSolve(A, b) solves the linear system without
%    preconditioners, using the default tolerances or those that have been
%    set previously in the option databases.
%
%    petscSolve(A, b, solver) specifies to use a
%    specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc.
%
%    petscSolve(A, b, solver, rtol) uses the given number
%        of solvers and the relative tolerarance.
%
%    petscSolve(A, b, solver, rtol, maxit) solves with
%        the given relative tolerances and maximum iteration count.
%
%    petscSolve(A, b, solver, rtol, maxit, pctype)
%    uses the specified preconditioner (those give by PETSC_PC*).
%    The preconditioner can be controlled by the PETSc option database.
%
%    petscSolve(A, b, solver, rtol, maxit, pctype,
%    pcopt) specifies additional control options for the preconditioner.
%    If solver is PETSC_KSPPREONLY, and pctype is a direct method (such as
%    PETSC_PCLU or PETSC_PCCHOLESKY), then pcopt may be used to specify
%    the solver packages for factorization (PETSC_MATSOLVER*). Otherwise,
%    pcopt may be 'left', 'right', or 'symmetric'.
%
%    petscSolve(A, b, solver, rtol, maxit, pctype,
%    pcopt, x0) usee x0 for the initial guess. x0 can be the same as x.
%
%    petscSolve(A, b, solver, rtol, maxit, pctype,
%    pcopt, x0, opts) can pass additional command-line options in a
%    string to PETSc.
%
% SEE ALSO: petscSolveCRS, petscMatCreateAIJFromCRS, petscVecCreateFromArray,
%           petscVecToArray, petscKSPSetup, petscKSPDriver, petscKSPCleanup

if nargin==0
    x = zeros(0,1); flag=int32(-1); relres=realmax;
    iter=int32(0); reshis = zeros(0,1); times=[0;0];
    return;
end

if isempty(coder.target) && ~exist(['petscSolveCRS.' mexext], 'file') && ...
        exist('run_petscSolveCRS_exe', 'file')
    % Is running in MATLAB and mex files are not available
    [x, flag, relres, iter, reshis, times] = run_petscSolveCRS_exe(varargin{:});
    fprintf('KSP setup took %g seconds and solver took %g seconds\n', times(1), times(2));
    return;
elseif isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file')
    error('You must have built either the executible built when running in MATLAB.');
end

[Arows, Acols, Avals] = crs_matrix(A);
b = varargin{2};

% Setup KSP
[flag, relres, iter, reshis, times] = petscSolveCRS(Arows, Acols, Avals, b, varargin{3:});

[flag, relres, iter, reshis, times] = petscSolveHdls(AMat, bVec, xVec, solver, ...
    double(rtol), int32(maxit), pctype, pcopt, x0Vec, opts);

petscMatDestroy(AMat);
petscVecDestroy(bVec);

x = petscVecToArray(xVec);
petscVecDestroy(xVec);

end

function test %#ok<DEFNU>
%!test
%!shared A, b, rowptr, colind, vals
%! A = sprand(100,100,0.3);
%! A = A + speye(100);
%! [rowptr, colind, vals] = crs_matrix(A);
%! b = rand(100,1);

%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b);
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, '');
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     '', 1.e-6);
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-6, int32(100));
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPTFQMR, 1.e-6, int32(100));
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-10, int32(10), PETSC_PCJACOBI, 'right', ...
%!     zeros(0,1), '-ksp_monitor_true_residual');
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-6, int32(100), PETSC_PCILU, '');
%!test
%! [x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPPREONLY, 1.e-6, int32(100), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);

end
