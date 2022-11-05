function [errCode, toplevel] = petscKSPSolve_2args(ksp, b)
[errCode, toplevel] = petscKSPSolve(ksp, b);
