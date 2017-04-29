function [x,flag,relres,iter,reshis,times] = petscSolveCRS_11args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts) %#codegen
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts);
