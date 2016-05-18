function [errCode, toplevel] = petscPCSetOperators_AforP(ksp, Amat) %#codegen
[errCode, toplevel] = petscPCSetOperators(ksp, Amat);
