function [x,flag,relres,iter] = mptSolveCRS_9args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack);
