function [flag,relres,iter,reshis,time] = mptKSPSolve_2args(ksp, b) %#codegen
[flag,relres,iter,reshis,time] = mptKSPSolve(ksp, b);
