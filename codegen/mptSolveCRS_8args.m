function [x,flag,relres,iter] = mptSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype);
