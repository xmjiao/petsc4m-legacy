function [ksp, time, toplevel] = mptKSPSetup_3args(Amat, ksptype, pctype) %#codegen
[ksp, time, toplevel] = mptKSPSetup(Amat, ksptype, pctype);
