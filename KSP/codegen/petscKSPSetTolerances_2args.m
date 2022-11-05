function [errCode, toplevel] = petscKSPSetTolerances_2args(ksp, rtol)
[errCode, toplevel] = petscKSPSetTolerances(ksp, rtol);
