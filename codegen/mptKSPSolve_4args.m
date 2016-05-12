function [x,flag,relres,iter,toplevel] = mptKSPSolve_4args(ksp, b, rtol, maxit) %#codegen
[x,flag,relres,iter,toplevel] = mptKSPSolve(ksp, b, rtol, maxit);
