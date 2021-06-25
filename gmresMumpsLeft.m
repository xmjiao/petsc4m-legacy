function varargout = gmresMumpsLeft(varargin)
% Solves a system using MATLAB's GMRES left-preconditioned with MUMPS
%
% Syntax:
%    x = gmresMumpsLeft(A, b) solves a sparse linear system using MATLAB's GMRES
%    solver with MUMPS as the left preconditioner. Matrix A can be in
%    MATLAB's built-in sparse format or in CRS format created using crs_matrix.
%
%    x = gmresMumpsLeft(rowptr, colind, vals, b) takes a matrix in the CRS
%    format instead of MATLAB's built-in sparse format.
%
%    x = gmresMumpsLeft(A, b, restart)
%    x = gmresMumpsLeft(rowptr, colind, vals, b, restart)
%    allows you to specify the restart parameter for GMRES. The default
%    value is 30. You can preserve the default value by passing [].
%
%    x = gmresMumpsLeft(A, b, restart, rtol, maxiter)
%    x = gmresMumpsLeft(rowptr, colind, vals, b, restart, rtol, maxiter)
%    allows you to specify the relative tolerance and the maximum number
%    of iterations. Their default values are 1.e-5 and 10000, respectively.
%    Use 0 or [] to preserve default values of rtol and maxiter.
%
%    x = gmresMumpsLeft(A, b, restart, rtol, maxiter, x0)
%    x = gmresMumpsLeft(rowptr, colind, vals, b, restart, rtol, maxiter, x0)
%    takes an initial solution in x0. Use 0 or [] to preserve the default
%    initial solution (all zeros).
%
%    [x, flag, relres, iter, resvec] = gmresMumpsLeft(...)
%    returns the solution vector x, the flag (KSPConvergedReason), relative
%    residual, number of iterations, and history of residual used in
%    convergence test (typically preconditioned residual).
%
% Note: This function is for illustrating the use of MUMPS
%   through PETSc. It should never be used for product runs
%   since using left-preconditioning is problematic.

if nargin==0
    help gmresMumpsLeft
    return;
end

if issparse(varargin{1})
    Asparse = varargin{1};
    [Arows, Acols, Avals] = crs_matrix(varargin{1});
    next_index = 2;
elseif isstruct(varargin{1})
    Arows = varargin{1}.row_ptr;
    Acols = varargin{1}.col_ind;
    Avals = varargin{1}.val;
    Asparse = crs_2sparse(Arows, Acols, Avals);
    next_index = 2;
else
    Arows = varargin{1};
    Acols = varargin{2};
    Avals = varargin{3};
    Asparse = crs_2sparse(Arows, Acols, Avals);
    next_index = 4;
end

if nargin<next_index
    error('The right hand-side must be specified');
else
    b = varargin{next_index};
end

if nargin >= next_index + 1 && ~isempty(varargin{next_index + 1})
    restart = varargin{next_index + 1};
else
    restart = 30;
end

if nargin >= next_index + 2 && ~isempty(varargin{next_index + 2})
    rtol = varargin{next_index + 2};
else
    rtol = [];
end

if nargin >= next_index + 3 && ~isempty(varargin{next_index + 3})
    maxiter = int32(varargin{next_index + 3});
else
    maxiter = [];
end

if nargin >= next_index + 4 && ~isempty(varargin{next_index + 4})
    x0 = varargin{next_index + 4};
else
    x0 = PetscScalar(zeros(0, 1));
end

opts = '';

% Make sure PETSc is initialized
if ~petscInitialized
  init_petsc;
end

% Create Mumps preconditioner
pc = pcCreate(Arows, Acols, PetscScalar(Avals), PETSC_MATSOLVERMUMPS, opts);

% Create function handle to apply preconditioner
Mfun = @(x) pcApply(pc, PetscScalar(x));

% Invoke MATLAB's built-in gmres
[varargout{1:nargout}] = gmres(Asparse, b, restart, PetscReal(rtol), maxiter, Mfun, [], x0);

% Destroy preconditioner context
pcDestroy(pc);

end

function test %#ok<DEFNU>
%!test
%!shared A, b
%! tmp = load('data/494_bus.mat');
%! A = tmp.Problem.A;
%! b = A*ones(size(A, 1), 1);
%! rtol = 10*eps(class(PetscReal(0))).^(1/2);

%! [x,flag,relres,iter,resvec] = gmresMumpsLeft(A, b, [], rtol);
%! assert(norm(b - A*double(x)) < 100*rtol * norm(b))

end
