function [x,flag,relres,iter,times] = mptSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype);
