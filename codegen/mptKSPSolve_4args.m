function [flag,relres,iter,reshis,time] = mptKSPSolve_4args(ksp, b, x, rtol) %#codegen
[flag,relres,iter,reshis,time] = mptKSPSolve(ksp, b, x, rtol);
