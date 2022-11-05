function [x,flag,relres,iter,reshis,times] = petscSolveCRS_9args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack)
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack);
