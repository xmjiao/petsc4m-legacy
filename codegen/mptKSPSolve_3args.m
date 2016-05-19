function [flag,relres,iter,time] = mptKSPSolve_3args(ksp, b, x) %#codegen
[flag,relres,iter,time] = mptKSPSolve(ksp, b, x);
