function [flag,relres,iter,time] = mptKSPSolve_5args(ksp, b, x, rtol, maxiter) %#codegen
[flag,relres,iter,time] = mptKSPSolve(ksp, b, x, rtol, maxiter);
