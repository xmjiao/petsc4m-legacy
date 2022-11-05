function [x,flag,relres,iter,reshis,times] = petscSolveCRS_4args(Arows, Acols, Avals, b)
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b);
