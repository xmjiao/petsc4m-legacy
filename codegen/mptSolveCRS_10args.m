function [x,flag,relres,iter,reshis,times] = mptSolveCRS_10args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0) %#codegen
[x,flag,relres,iter,reshis,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0);
