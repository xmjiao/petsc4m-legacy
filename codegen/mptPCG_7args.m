function [x,flag,relres,iter,resvec,toplevel] = mptPCG_7args(Amat, b, rtol, maxit, pctype, pcpre, resvec) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b, rtol, maxit, pctype, pcpre, resvec);
