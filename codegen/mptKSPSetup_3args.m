function [ksp, toplevel] = mptKSPSetup_3args(Amat, PMat, ksptype) %#codegen
[ksp, toplevel] = mptKSPSetup(Amat, PMat, ksptype);
