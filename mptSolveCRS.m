function [x, flag, relres, iter, reshis, times] = mptSolveCRS(varargin)
% Solves a linear system using any PETSc solver for matrix in CRS format.
%
% Syntax:
%    mptSolveCRS(Arows, Acols, Avals, b)
%    mptSolveCRS(Arows, Acols, Avals, b, solver)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, pcopt)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, pcopt, x0)
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, pcopt, x0, opts)
%
%    [x, flag, relres, iter, reshis, times] = mptSolveCRS(Arows, Acols, Avals, b, ...)
%    returns the solution vector x, the flag (KSPConvergedReason), relative
%    residual, number of iterations, history of residual used in convergence
%    test (typically preconditioned residual), and the execution times in
%    setup and solve.
%
%    A is a sparse matrix in CRS format. b, x and resvec are all regular
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
%    mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without
%    preconditioners, using the default tolerances or those that have been
%    set previously in the option databases.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a
%    specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number
%        of solvers and the relative tolerarance.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with
%        the given relative tolerances and maximum iteration count.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype)
%    uses the specified preconditioner (those give by PETSC_PC*).
%    The preconditioner can be controlled by the PETSc option database.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype,
%    pcopt) specifies additional control options for the preconditioner.
%    If solver is PETSC_KSPPREONLY, and pctype is a direct method (such as
%    PETSC_PCLU or PETSC_PCCHOLESKY), then pcopt may be used to specify
%    the solver packages for factorization (PETSC_MATSOLVER*). Otherwise,
%    pcopt may be 'left', 'right', or 'symmetric'.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype,
%    pcopt, x0) usee x0 for the initial guess. x0 can be the same as x.
%
%    mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype,
%    pcopt, x0, opts) can pass additional command-line options in a
%    string to PETSc.
%
% SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray,
%           mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup

%#codegen -args {}
%#codegen mptSolveCRS_4args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1])}
%#codegen mptSolveCRS_5args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType}
%#codegen mptSolveCRS_6args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType, 0}
%#codegen mptSolveCRS_7args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType, 0, int32(0)}
%#codegen mptSolveCRS_8args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType, 0, int32(0), PetscPCType}
%#codegen mptSolveCRS_9args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType, 0, int32(0),
%#codegen PetscPCType, PetscMatSolverPackage}
%#codegen mptSolveCRS_10args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType, 0, int32(0),
%#codegen PetscPCType, PetscMatSolverPackage, coder.typeof(0, [inf,1])}
%#codegen mptSolveCRS_11args -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(0, [inf,1]), coder.typeof(0, [inf,1]), PetscKSPType,
%#codegen 0, int32(0), PetscPCType, PetscMatSolverPackage,
%#codegen coder.typeof(0, [inf,1]), coder.typeof(char(0), [1, inf])}

if nargin==0
    x = zeros(0,1); flag=int32(-1); relres=realmax;
    iter=int32(0); reshis = zeros(0,1); times=[0;0];
    return;
end

if isempty(coder.target) && ~exist(['mptSolveCRS.' mexext], 'file') && ...
        exist('run_mptSolveCRS_exe', 'file')
    % Is running in MATLAB and mex files are not available
    [x, flag, relres, iter, reshis, times] = run_mptSolveCRS_exe(varargin{:});
    fprintf('KSP setup took %g seconds and solver took %g seconds\n', times(1), times(2));
    return;
elseif isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file')
    error('You must have built either the executible built when running in MATLAB.');
end

Arows = varargin{1};
Acols = varargin{2};
Avals = varargin{3};
b = varargin{4};

% Setup KSP
if nargin<5; solver = ''; else solver = varargin{5}; end % Use default
if nargin<6; rtol = 0; else rtol = varargin{6}; end
if nargin<7; maxit = int32(0); else maxit = varargin{7}; end
if nargin<8; pctype = ''; else pctype = varargin{8}; end
if nargin<9; pcopt = ''; else pcopt = varargin{9}; end

AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
bVec = mptVecCreateFromArray(b);

if nargin<10 || isempty(varargin{10})
    x0Vec = PETSC_NULL_VEC;
    xVec = petscVecDuplicate(bVec);
else
    x0 = varargin{10};
    x0Vec = mptVecCreateFromArray(x0);
    xVec = x0Vec;
end

if nargin<11; opts = ''; else opts = varargin{11}; end

[flag, relres, iter, reshis, times] = mptSolve(AMat, bVec, xVec, solver, ...
    double(rtol), int32(maxit), pctype, pcopt, x0Vec, opts);

petscMatDestroy(AMat);
petscVecDestroy(bVec);

x = mptVecToArray(xVec);
petscVecDestroy(xVec);

end

function test %#ok<DEFNU>
%!test
%!shared A, b, rowptr, colind, vals
%! A = sprand(100,100,0.3);
%! A = A + speye(100);
%! B = bsrCreateFromSparse(A);
%! rowptr = B.rowptr; colind=B.colind; vals=B.vals;
%! b = rand(100,1);

%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b);
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, '');
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     '', 1.e-6);
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-6, int32(100));
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPTFQMR, 1.e-6, int32(100));
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-10, int32(10), PETSC_PCJACOBI, 'right', ...
%!     zeros(0,1), '-ksp_monitor_true_residual');
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPBCGS, 1.e-6, int32(100), PETSC_PCILU, '');
%!test
%! [x,flag,relres,iter,reshis,times] = mptSolveCRS(rowptr, colind, vals, b, ...
%!     PETSC_KSPPREONLY, 1.e-6, int32(100), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);

end
