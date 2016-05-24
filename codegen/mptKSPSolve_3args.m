function [flag,relres,iter,reshis,time] = mptKSPSolve_3args(ksp, b, x) %#codegen
[flag,relres,iter,reshis,time] = mptKSPSolve(ksp, b, x);
