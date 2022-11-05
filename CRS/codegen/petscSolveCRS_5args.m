function [x,flag,relres,iter,reshis,times] = petscSolveCRS_5args(Arows, Acols, Avals, b, solver)
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver);
