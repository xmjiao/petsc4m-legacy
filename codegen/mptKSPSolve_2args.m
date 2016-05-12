function [x,flag,relres,iter,toplevel] = mptKSPSolve_2args(ksp, b) %#codegen
[x,flag,relres,iter,toplevel] = mptKSPSolve(ksp, b);
