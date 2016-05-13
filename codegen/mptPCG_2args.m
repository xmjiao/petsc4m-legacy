function [x,flag,relres,iter,resvec,toplevel] = mptPCG_2args(Amat, b) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b);
