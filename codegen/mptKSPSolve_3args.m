function [flag,relres,iter] = mptKSPSolve_3args(ksp, b, x) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b, x);
