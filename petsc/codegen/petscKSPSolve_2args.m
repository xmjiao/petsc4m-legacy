function [errCode, toplevel] = petscKSPSolve_2args(ksp, b) %#codegen
[errCode, toplevel] = petscKSPSolve(ksp, b);
