function [flag, relres, iter, reshis, times] = petscSolve(A, b, x, solver, ...
    rtol, maxit, pctype, pcopt, x0, opts)
% Solves a linear system using a given solver in PETSc.
%
% Syntax:
%    petscSolve(A_hdl, b_hdl)
%    petscSolve(A_hdl, b_hdl, x_hdl)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt, x0_hdl)
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt, x0_hdl, opts)
%
%    [flag, relres, iter, reshis, times] = petscSolve(A_hdl, b_hdl, x_hdl, ...)
%    returns the flag (KSPConvergedReason), relative residual, number of 
%    iterations, history of residual used in convergence test (typically 
%    preconditioned residual), and the execution times spent in its core steps.
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    petscSolve(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The QMRCGS can be
%    controlled using the options database for KSPQMRCGS.
%
%    petscSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where
%    solver is one of PETSC_KSP*.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given
%     relative tolerances and maximum iteration count.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the
%    specified preconditioner (PETSC_PC*). The preconditioner can be
%    controlled by the PETSc option database.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt)
%    aspecifies additional control options for the preconditioner.
%    If solver is PETSC_KSPPREONLY, and pctype is a direct method (such as
%    PETSC_PCLU or PETSC_PCCHOLESKY), then pcopt may be used to specify
%    the solver packages for factorization (PETSC_MATSOLVER*). Otherwise,
%    pcopt may be 'left', 'right', or 'symmetric'.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt,
%    x0_handle) usee x0 for the initial guess. x0 can be the same as x or
%    be PETSC_NULL_VEC.
%
%    petscSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, pcopt,
%    x0_handle, opts) can pass command-line options in a string to PETSc.
%
% SEE ALSO: petscSolveCRS, petscMatCreateAIJFromCRS, petscVecCreateFromArray,
%           petscOptionsInsert, petscKSPSetup, petscKSPDriver, petscKSPCleanup

%This function is codegen compatbile, but no need to a top-level function
% Setup KSP
if nargin<3; x = b; end
if nargin<4; solver = ''; end
if nargin<5; rtol = 0; end
if nargin<6; maxit = int32(0); end
if nargin<7; pctype = ''; end
if nargin<8; pcopt = ''; end
if nargin<9; x0 = PETSC_NULL_VEC; end

if nargin==10 && ~isempty(opts)
    petscOptionsInsert(opts);
end

[ksp, time_setup] = petscKSPSetup(A, solver, pctype, pcopt);

[flag, relres, iter, reshis, time_solve] = petscKSPDriver(ksp, b, x, ...
    double(rtol), int32(maxit), x0);

if nargout>4
    times = [time_setup; time_solve];
end

petscKSPCleanup(ksp);

end
