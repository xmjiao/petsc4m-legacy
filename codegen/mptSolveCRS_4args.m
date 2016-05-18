function [x,flag,relres,iter, rv] = mptSolveCRS_4args(Arows, Acols, Avals, b) %#codegen
[x,flag,relres,iter, rv] = mptSolveCRS(Arows, Acols, Avals, b);
