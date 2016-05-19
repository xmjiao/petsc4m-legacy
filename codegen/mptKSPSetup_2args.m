function [ksp, time, toplevel] = mptKSPSetup_2args(Amat, ksptype) %#codegen
[ksp, time, toplevel] = mptKSPSetup(Amat, ksptype);
