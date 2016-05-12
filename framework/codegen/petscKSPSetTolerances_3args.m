function [errCode, toplevel] = petscKSPSetTolerances_3args(ksp, rtols, maxits) %#codegen
[errCode, toplevel] = petscKSPSetTolerances(ksp, rtols, maxits);
