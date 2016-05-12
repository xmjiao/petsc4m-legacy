function [errCode, toplevel] = petscPCApplyTranspose_2args(ksp, b) %#codegen
[errCode, toplevel] = petscPCApplyTranspose(ksp, b);
