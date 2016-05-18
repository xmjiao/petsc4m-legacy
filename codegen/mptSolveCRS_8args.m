function [x,flag,relres,iter, rv] = mptSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype) %#codegen
[x,flag,relres,iter, rv] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype);
