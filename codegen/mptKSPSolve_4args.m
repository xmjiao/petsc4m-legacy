function [flag,relres,iter] = mptKSPSolve_4args(ksp, b, x, rtol) %#codegen
[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol);
