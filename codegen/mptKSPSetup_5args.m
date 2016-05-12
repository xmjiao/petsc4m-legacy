function [ksp, toplevel] = mptKSPSetup_5args(Amat, PMat, ksptype, ksppre, pctype) %#codegen
[ksp, toplevel] = mptKSPSetup(Amat, PMat, ksptype, ksppre, pctype);
