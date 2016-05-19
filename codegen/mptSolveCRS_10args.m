function [x,flag,relres,iter,times] = mptSolveCRS_10args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0);
