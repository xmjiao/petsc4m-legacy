function [x,flag,relres,iter, rv] = mptSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol) %#codegen
[x,flag,relres,iter, rv] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol);
