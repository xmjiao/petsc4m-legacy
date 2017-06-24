function [x, flag, times] = directSolve(varargin)
% Solves a sparse system using a direct solver
%
% Syntax:
%    x = directSolve(A, b) solves a sparse linear system for a matrix in
%    MATLAB's built-in sparse format using an LU-based direct solver.
%
%    x = directSolve(rowptr, colind, vals, b) takes a matrix in the CRS
%    format instead of MATLAB's built-in sparse format.
%
%    x = directSolve(A, b, solver)
%    x = directSolve(rowptr, colind, vals, b, solver) 
%    allows you to specify a particular external solver, where the
%    solver can be PETSC_MATSOLVER*. The default is PETSC_MATSOLVERUMFPACK.
%
%    [x, flag, times] = directSolve(...)
%    returns the solution vector x, the flag (KSPConvergedReason), and 
%    the execution times in setup and solve.
%

if nargin==0
    help directSolve
    return;
end

if issparse(varargin{1})
    [Arows, Acols, Avals] = crs_matrix(varargin{1});
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

if nargin >= next_index+1 && ~isempty(varargin{next_index+1})
    solver = varargin{next_index+1};
else
    solver = PETSC_MATSOLVERUMFPACK;
end

[x, flag, ~, ~, ~, times]  = petscSolveCRS(Arows, Acols, Avals, ...
    b, PETSC_KSPPREONLY, 0, int32(0), PETSC_PCLU, solver);
end

function test %#ok<DEFNU>
%!test
%!shared A, b
%! system('gd-get -q -O -p 0ByTwsK5_Tl_PemN0QVlYem11Y00 fem2d"*".mat');
%! s = load('fem2d_cd.mat');
%! A = s.A;
%! s = load('fem2d_vec_cd.mat');
%! b = s.b;

%! [x, flag, times] = directSolve(A, b);
%! assert(norm(b - A*x) < 1.e-12 * norm(b))

end
