function [flag,relres,iter] = mptKSPSolve_7args(ksp, b, x, rtol, maxiter, x0, resvec) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxiter, x0, resvec);
