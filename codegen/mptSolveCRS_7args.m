function [x,flag,relres,iter] = mptSolveCRS_7args(Arows, Acols, Avals, b, solver, rtol, maxiter) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter);
