function [x,flag,relres,iter,resvec,toplevel] = mptPCG_3args(Amat, b, rtol) %#codegen
 [x,flag,relres,iter,resvec,toplevel] = mptPCG(Amat, b, rtol);
