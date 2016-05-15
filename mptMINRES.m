function [flag,relres,iter] = mptMINRES(A, b, x, rtol, maxit, pctype, solpack, varargin)
% Solves a symmetric/Hermitian linear system using the Minimal Residual method.
%
% Syntax:
%    mptMINRES(A_hdl, b_hdl)
%    mptMINRES(A_hdl, b_hdl, x_hdl)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack, x0_hdl)
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack, x0_hdl, resvec_hdl)
%
%    [flag, reslres, iter] = mptMINRES(A_hdl, b_hdl, x_hdl, ...)
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    mptMINRES(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The MINRES can be
%    controlled using the options database for KSPMINRES.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol) uses the given relative tolerarance.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit) solves with the given relative
%    tolerances and maximum iteration count.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype) uses the
%    specified preconditioner. The preconditioner can be controlled by
%    the PETSc option database.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack) specifies
%    the solver packages for factorization.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack, x0_handle)
%    usee x0 for the initial guess. x0 can be the same as x.
%
%    mptMINRES(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, solpack, x0_handle, resvec_hdl)
%    also computes the residual vector and saves it into resvec.
%
% See also: mptCG, mptGMRES, mptBCGS, mptTFQMR, mptQMRCGS
%           mptKSPSetup, mptKSPSolve, mptKSPCleanup
%
% PETSC: http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPMINRES.html

%#codegen

% Setup KSP
if nargin<3; x = b; end
if nargin<4; rtol = PETSC_DEFAULT; end
if nargin<5; maxit = PETSC_DEFAULT; end
if nargin<6; pctype = ''; end
if nargin<7; solpack = ''; end

ksp = mptKSPSetup(A, PETSC_KSPMINRES, pctype, solpack);

[flag,relres,iter] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), varargin{:});

mptKSPCleanup(ksp);

end
