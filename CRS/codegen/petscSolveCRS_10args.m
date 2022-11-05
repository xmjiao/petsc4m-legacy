function [x,flag,relres,iter,reshis,times] = petscSolveCRS_10args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0)
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0);
