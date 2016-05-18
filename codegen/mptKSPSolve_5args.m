function [flag,relres,iter] = mptKSPSolve_5args(ksp, b, x, rtol, maxiter) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxiter);
