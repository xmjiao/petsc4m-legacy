function [flag,relres,iter,time] = mptKSPSolve_2args(ksp, b) %#codegen
[flag,relres,iter,time] = mptKSPSolve(ksp, b);
