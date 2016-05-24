function [x,flag,relres,iter,reshis,times] = mptSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype) %#codegen
[x,flag,relres,iter,reshis,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype);
