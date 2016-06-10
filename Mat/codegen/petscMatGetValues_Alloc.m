function [v, errCode, toplevel] = petscMatGetValues_Alloc(mat, ni, ix, nj, jx) %#codegen
[v, errCode, toplevel] = petscMatGetValues(mat, ni, ix, nj, jx);
