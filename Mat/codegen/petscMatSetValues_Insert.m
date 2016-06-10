function [errCode, toplevel] = petscMatSetValues_Insert(mat, ni, ix, nj, jx, v)
[errCode, toplevel] = petscMatSetValues(mat, ni, ix, nj, jx, v);
