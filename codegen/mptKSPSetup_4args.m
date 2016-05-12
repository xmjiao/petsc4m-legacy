function [ksp, toplevel] = mptKSPSetup_4args(Amat, PMat, ksptype, ksppre) %#codegen
[ksp, toplevel] = mptKSPSetup(Amat, PMat, ksptype, ksppre);
