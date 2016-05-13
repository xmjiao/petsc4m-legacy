function [flag,relres,iter] = mptKSPSolve_6args(ksp, b, x, rtol, maxiter, x0) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxiter, x0);
