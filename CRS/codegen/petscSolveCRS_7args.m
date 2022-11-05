function [x,flag,relres,iter,reshis,times] = petscSolveCRS_7args(Arows, Acols, Avals, b, solver, rtol, maxiter)
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter);
