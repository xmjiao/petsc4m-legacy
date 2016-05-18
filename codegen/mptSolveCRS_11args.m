function [x,flag,relres,iter, rv] = mptSolveCRS_11args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts) %#codegen
[x,flag,relres,iter, rv] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts);
