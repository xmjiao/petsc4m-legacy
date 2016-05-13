function [x,flag,relres,iter,resvec,toplevel] = mptPCG_5args(Amat, b, rtol, maxit, pctype) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b, rtol, maxit, pctype);
