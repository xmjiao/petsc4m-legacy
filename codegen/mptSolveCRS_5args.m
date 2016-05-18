function [x,flag,relres,iter] = mptSolveCRS_5args(Arows, Acols, Avals, b, solver) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b, solver);
