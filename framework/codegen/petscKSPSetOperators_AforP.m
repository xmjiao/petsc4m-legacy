function [errCode, toplevel] = petscKSPSetOperators_AforP(ksp, Amat) %#codegen
[errCode, toplevel] = petscKSPSetOperators(ksp, Amat);
