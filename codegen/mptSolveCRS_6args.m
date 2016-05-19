function [x,flag,relres,iter,times] = mptSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol);
