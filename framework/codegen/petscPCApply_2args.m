function [errCode, toplevel] = petscPCApply_2args(ksp, b) %#codegen
[errCode, toplevel] = petscPCApply(ksp, b);
