function [errCode, toplevel] = petscPCSetOperators_AforP(ksp, Amat)
[errCode, toplevel] = petscPCSetOperators(ksp, Amat);
