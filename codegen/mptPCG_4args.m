function [x,flag,relres,iter,resvec,toplevel] = mptPCG_4args(Amat, b, rtol, maxit) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b, rtol, maxit);
