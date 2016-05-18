function errCode = petscMatSetValues_Insert(mat, ni, ix, nj, jx, v) %#codegen
errCode = petscMatSetValues(mat, ni, ix, nj, jx, v);
