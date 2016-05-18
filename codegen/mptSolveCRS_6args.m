function [x,flag,relres,iter] = mptSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol) %#codegen
[x,flag,relres,iter] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol);
