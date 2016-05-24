function [x,flag,relres,iter,reshis,times] = mptSolveCRS_11args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts) %#codegen
[x,flag,relres,iter,reshis,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts);
