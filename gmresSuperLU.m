function varargout = gmresSuperLU(varargin)
% Solves a sparse system using GMRES with SuperNodal ILU in SuperLU as right-preconditioning
%
% Syntax:
%    x = gmresSuperLU(A, b) solves a sparse linear system using PETSc's GMRES
%    solver with SuperLU's SuperILU as the right preconditioner. Matrix A can be in
%    MATLAB's built-in sparse format or in CRS format created using crs_matrix.
%
%    x = gmresSuperLU(rowptr, colind, vals, b) takes a matrix in the CRS
%    format instead of MATLAB's built-in sparse format.
%
%    x = gmresSuperLU(A, b, restart)
%    x = gmresSuperLU(rowptr, colind, vals, b, restart)
%    allows you to specify the restart parameter for GMRES. The default
%    value is 30. You can preserve the default value by passing [].
%
%    x = gmresSuperLU(A, b, restart, rtol, maxiter)
%    x = gmresSuperLU(rowptr, colind, vals, b, restart, rtol, maxiter) 
%    allows you to specify the relative tolerance and the maximum number 
%    of iterations. Their default values are 1.e-5 and 10000, respectively. 
%    Use 0 or [] to preserve default values of rtol and maxiter.
%
%    x = gmresSuperLU(A, b, restart, rtol, maxiter, x0)
%    x = gmresSuperLU(rowptr, colind, vals, b, restart, rtol, maxiter, x0) 
%    takes an initial solution in x0. Use 0 or [] to preserve the default 
%    initial solution (all zeros).
%
%    x = gmresSuperLU(A, b, restart, rtol, maxit, x0, opts)
%    allows you to specify additional options in a string (such as 
%    '-mat_superlu_ilu_droptol 0.001'). 
%    See https://petsc-users.mcs.anl.narkive.com/8UsgiInN/superlu-options-database
%    
%    [x, flag, relres, iter, reshis, times] = gmresSuperLU(...)
%    returns the solution vector x, the flag (KSPConvergedReason), relative
%    residual, number of iterations, history of residual used in convergence
%    test (typically preconditioned residual), and the execution times in
%    setup and solve.
%
% SEE ALSO: petscSolveCRS

if nargin==0
    help gmresSuperLU
    return;
end

if issparse(varargin{1})
    [Arows, Acols, Avals] = crs_matrix(varargin{1});
    next_index = 2;
elseif isstruct(varargin{1})
    Arows = varargin{1}.row_ptr;
    Acols = varargin{1}.col_ind;
    Avals = varargin{1}.val;
    next_index = 2;
else
    Arows = varargin{1};
    Acols = varargin{2};
    Avals = varargin{3};
    next_index = 4;
end

if nargin<next_index
    error('The right hand-side must be specified');
else
    b = varargin{next_index};
end

if nargin >= next_index + 1 && ~isempty(varargin{next_index + 1})
    opts = [' -ksp_gmres_restart ' int2str(varargin{next_index + 1})];
else
    opts = ' -ksp_gmres_restart 30';
end

if nargin >= next_index + 2 && ~isempty(varargin{next_index + 2})
    rtol = varargin{next_index + 2};
else
    rtol = 0;
end

if nargin >= next_index + 3 && ~isempty(varargin{next_index + 3})
    maxiter = int32(varargin{next_index + 3});
else
    maxiter = int32(0);
end

if nargin >= next_index + 4 && ~isempty(varargin{next_index + 4})
    x0 = varargin{next_index + 4};
else
    x0 = zeros(0, 1);
end

if nargin >= next_index + 5 && ~isempty(varargin{next_index + 5})
    opts = [opts ' -pc_type ilu -pc_factor_mat_solver_package superlu' varargin{next_index + 5}];
else
    opts = [opts ' -pc_type ilu -pc_factor_mat_solver_package superlu'];
end

[varargout{1:nargout}] = petscSolveCRS(Arows, Acols, Avals, ...
    b, PETSC_KSPGMRES, rtol, maxiter, PETSC_PCHYPRE, 'right', x0, opts);
end

function test %#ok<DEFNU>
%!test
%!shared A, b
%! system('gd-get -q -O -p 0ByTwsK5_Tl_PemN0QVlYem11Y00 fem2d"*".mat');
%! s = load('fem2d_cd.mat');
%! A = s.A;
%! s = load('fem2d_vec_cd.mat');
%! b = s.b;
%! rtol = 1.e-5;

%! [x,flag,relres,iter,reshis,times] = gmresSuperLU(A, b, [], rtol);
%! assert(norm(b - A*x) < rtol * norm(b))

end
