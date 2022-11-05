function [v, errCode, toplevel] = petscMatGetValues_Alloc(mat, ni, ix, nj, jx)
[v, errCode, toplevel] = petscMatGetValues(mat, ni, ix, nj, jx);
