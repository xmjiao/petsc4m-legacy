function [x,flag,relres,iter] = mptSolveCRS_4args(Arows, Acols, Avals, b) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b);
