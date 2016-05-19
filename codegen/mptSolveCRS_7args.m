function [x,flag,relres,iter,times] = mptSolveCRS_7args(Arows, Acols, Avals, b, solver, rtol, maxiter) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter);
