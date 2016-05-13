function [x,flag,relres,iter,resvec,toplevel] = mptPCG_6args(Amat, b, rtol, maxit, pctype, pcpre) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b, rtol, maxit, pctype, pcpre);
