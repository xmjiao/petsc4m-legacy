function [x,flag,relres,iter,reshis,times] = mptSolveCRS_4args(Arows, Acols, Avals, b) %#codegen
[x,flag,relres,iter,reshis,times] = mptSolveCRS(Arows, Acols, Avals, b);
