function [ksp, toplevel] = mptKSPSetup_6args(Amat, PMat, ksptype, ksppre, pctype, pcpre) %#codegen
[ksp, toplevel] = mptKSPSetup(Amat, PMat, ksptype, ksppre, pctype, pcpre);
