function [ksp, toplevel] = mptKSPSetup_3args(Amat, ksptype, pctype) %#codegen
[ksp, toplevel] = mptKSPSetup(Amat, ksptype, pctype);
