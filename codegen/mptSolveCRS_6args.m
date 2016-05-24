function [x,flag,relres,iter,reshis,times] = mptSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol) %#codegen
[x,flag,relres,iter,reshis,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol);
