function [x,flag,relres,iter,toplevel] = mptKSPSolve_3args(ksp, b, rtol) %#codegen
[x,flag,relres,iter,toplevel] = mptKSPSolve(ksp, b, rtol);
