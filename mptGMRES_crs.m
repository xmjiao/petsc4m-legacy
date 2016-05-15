function [x,flag,relres,iter, rv] = mptGMRES_crs(Arows, Acols, Avals, b, ...
    restart, rtol, maxit, pctype, solpack, x0)
% Solves a linear system using the restarted GMRES method for CRS format.
%
% Syntax:
%    mptGMRES_crs(Arows, Acols, Avals, b)
%    mptGMRES_crs(Arows, Acols, Avals, b)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype, solpack)
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype, solpack, x0)
%
%    [x, flag, reslres, iter, resvec] = mptGMRES_crs(Arows, Acols, Avals, b, ...)
%
%    A is a sparse matrix in CRS format. b, x and resvec are all regular
%    vectors.
%
% Description:
%    mptGMRES_crs(Arows, Acols, Avals, b) solves the linear system without
%    preconditioners, using the default tolerances or those that have been
%    set previously in the option databases.
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart) uses the given restart value.
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol) uses the given number
%        of restarts and the relative tolerarance.
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit) solves with
%        the given relative tolerances and maximum iteration count.
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype)
%    uses the specified preconditioner (those give by PETSC_PC*).
%    The preconditioner can be controlled by the PETSc option database.
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype,
%    solpack) specifies the solver packages for factorization (those give
%    by PETSC_MATSOLVER*).
%
%    mptGMRES_crs(Arows, Acols, Avals, b, restart, rtol, maxit, pctype,
%    solpack, x0) usee x0 for the initial guess. x0 can be the same as x.
%
% See also: mptCG, mptMINRES, mptBCGS, mptTFQMR, mptGMRES, mptQMRCGS,
%           mptKSPSetup, mptKSPSolve, mptKSPCleanup

%#codegen

% Setup KSP
if nargin<5; restart = int32(0); end % Use default
if nargin<6; rtol = PETSC_DEFAULT; end
if nargin<7; maxit = PETSC_DEFAULT; end
if nargin<8; pctype = ''; end
if nargin<9; solpack = ''; end

AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
bVec = mptVecCreateFromArray(b);

if nargin<10
    x0Vec = PETSC_NULL_VEC;
    xVec = petscVecDuplicate(bVec);
else
    x0Vec = mptVecCreateFromArray(x0);
    xVec = x0Vec;
end

if nargout==5
    resVec = petscVecDuplicate(b);
    [flag,relres,iter] = mptGMRES(AMat, bVec, xVec, int32(restart), ...
        double(rtol), int32(maxit), pctype, solpack, x0Vec, resVec);
    rv = mptVecToArray(resVec);
    petscVecDestroy(resVec);
else
    [flag,relres,iter] = mptGMRES(AMat, bVec, xVec, int32(restart), ...
        double(rtol), int32(maxit), pctype, solpack, x0Vec);
end

petscMatDestroy(AMat);
petscVecDestroy(bVec);

x = mptVecToArray(xVec);
petscVecDestroy(xVec);

end

function test %#ok<DEFNU>
%!test
%! rng(100);
%! A = sprand(100,100,0.3);
%! A = A + eye(100, 'like', A);
%! [rowptr, colind, val] = crs_createFromSparse(A); % This requires NumGeom
%! b = rand(100,1);
%! x0 = A\b;
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6, 100);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6, 100);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6, 100, PETSC_PCJACOBI);
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6, 100, PETSC_PCILU, '');
%! [x,flag,relres,iter] = mptGMRES_crs(rowptr, colind, val, b, 30, 1.e-6, 100, PETSC_PCLU, PETSC_MATSOLVERSUPERLU);
end
