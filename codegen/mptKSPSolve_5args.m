function [x,flag,relres,iter,toplevel] = mptKSPSolve_5args(ksp, b, rtol, maxit, x) %#codegen
[x,flag,relres,iter,toplevel] = mptKSPSolve(ksp, b, rtol, maxit, x);
