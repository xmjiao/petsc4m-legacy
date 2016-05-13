function [flag,relres,iter] = mptKSPSolve_2args(ksp, b) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b);
