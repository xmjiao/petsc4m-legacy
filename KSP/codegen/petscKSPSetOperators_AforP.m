function [errCode, toplevel] = petscKSPSetOperators_AforP(ksp, Amat)
[errCode, toplevel] = petscKSPSetOperators(ksp, Amat);
