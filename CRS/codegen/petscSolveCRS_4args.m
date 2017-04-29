function [x,flag,relres,iter,reshis,times] = petscSolveCRS_4args(Arows, Acols, Avals, b) %#codegen
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b);
