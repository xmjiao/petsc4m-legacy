function [flag,relres,iter,reshis,time] = mptKSPSolve_5args(ksp, b, x, rtol, maxiter) %#codegen
[flag,relres,iter,reshis,time] = mptKSPSolve(ksp, b, x, rtol, maxiter);
