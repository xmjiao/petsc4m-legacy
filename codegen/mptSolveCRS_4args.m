function [x,flag,relres,iter,times] = mptSolveCRS_4args(Arows, Acols, Avals, b) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b);
