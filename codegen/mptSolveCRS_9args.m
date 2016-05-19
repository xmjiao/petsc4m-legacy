function [x,flag,relres,iter,times] = mptSolveCRS_9args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack) %#codegen
[x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack);
