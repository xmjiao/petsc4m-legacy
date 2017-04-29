function [x,flag,relres,iter,reshis,times] = petscSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol) %#codegen
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol);
