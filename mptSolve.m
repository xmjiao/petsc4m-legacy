function [flag,relres,iter] = mptSolve(A, b, x, solver, rtol, maxit, ...
    pctype, solpack, x0, resvec, opts)
% Solves a linear system using a given solver in PETSc.
%
% Syntax:
%    mptSolve(A_hdl, b_hdl)
%    mptSolve(A_hdl, b_hdl, x_hdl)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl)
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl,
%             resvec_hdl, opts)
%
%    [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...)
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The QMRCGS can be
%    controlled using the options database for KSPQMRCGS.
%
%    mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where
%    solver is one of PETSC_KSP*.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given
%     relative tolerances and maximum iteration count.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the
%    specified preconditioner (PETSC_PC*). The preconditioner can be
%    controlled by the PETSc option database.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack)
%    specifies the solver packages for factorization (PETSC_MATSOLVER*).
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack,
%    x0_handle) usee x0 for the initial guess. x0 can be the same as x or
%    be PETSC_NULL_VEC.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack,
%    x0_handle, resvec_hdl) also computes the residual vector and saves
%    it into resvec. resvec_hdl can be PETSC_NULL_VEC.
%
%    mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack,
%    x0_handle, resvec_hdl, opts) can pass additional command-line options
%    in a string to PETSc.
%
% SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray,
%           mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup

%This function is codegen compatbile, but no need to a top-level function
%#codegen

% Setup KSP
if nargin<3; x = b; end
if nargin<4; solver = ''; end
if nargin<5; rtol = double(PETSC_DEFAULT); end
if nargin<6; maxit = PETSC_DEFAULT; end
if nargin<7; pctype = ''; end
if nargin<8; solpack = ''; end
if nargin<9; x0 = PETSC_NULL_VEC; end
if nargin<10; resvec = PETSC_NULL_VEC; end

if nargin==11 && ~isempty(opts)
    mptOptionsInsert(opts);
end

ksp = mptKSPSetup(A, solver, pctype, solpack);

[flag,relres,iter] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0, resvec);

mptKSPCleanup(ksp);

end
