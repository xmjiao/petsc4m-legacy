function [x,flag,relres,iter, rv] = mptSolveCRS_7args(Arows, Acols, Avals, b, solver, rtol, maxiter) %#codegen
[x,flag,relres,iter, rv] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter);
