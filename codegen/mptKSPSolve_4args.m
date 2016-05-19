function [flag,relres,iter,time] = mptKSPSolve_4args(ksp, b, x, rtol) %#codegen
[flag,relres,iter,time] = mptKSPSolve(ksp, b, x, rtol);
