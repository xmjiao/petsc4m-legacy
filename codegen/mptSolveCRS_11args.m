function [x,flag,relres,iter,times] = mptSolveCRS_11args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts);
