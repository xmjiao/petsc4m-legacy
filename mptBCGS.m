function [flag,relres,iter] = mptBCGS(A, b, x, rtol, maxit, pctype, pcprefix, varargin)
% Solves a linear system using the BiCGStab (Stabilized version of BiConjugate Gradient Squared) method.
%
% Syntax:
%    mptBCGS(A_hdl, b_hdl)
%    mptBCGS(A_hdl, b_hdl, x_hdl)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_hdl)
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_hdl, resvec_hdl)
%
%    [flag, reslres, iter] = mptBCGS(A_hdl, b_hdl, x_hdl, ...)
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    mptBCGS(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The BCGS can be
%    controlled using the options database for KSPBCGS.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol) uses the given relative tolerarance.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit) solves with the given relative
%    tolerances and maximum iteration count.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype) uses the
%    specified preconditioner. The preconditioner can be controlled by
%    the PETSc option database.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix) specifies
%    the prefix for the options in the PETSc option database.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_handle)
%    usee x0 for the initial guess. x0 can be the same as x.
%
%    mptBCGS(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_handle, resvec_hdl)
%    also computes the residual vector and saves it into resvec.
%
% See also: mptCG, mptMINRES, mptGMRES, mptTFQMR, mptQMRCGS,
%           mptKSPSetup, mptKSPSolve, mptKSPCleanup
%
% PETSC: http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPBCGS.html

%#codegen

% Setup KSP
if nargin<2; x = b; end
if nargin<3; rtol = PETSC_DEFAULT; end
if nargin<4; maxit = PETSC_DEFAULT; end
if nargin<5; pctype = PETSC_PCNONE; end
if nargin<6; pcprefix = ''; end

ksp = mptKSPSetup(A, PETSC_KSPBCGS, pctype, pcprefix);

[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxit, varargin{:});

mptKSPCleanup(ksp);

end
