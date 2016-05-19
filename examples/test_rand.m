% Set up a test matrix
rng(100);
A = sprand(100,100,0.3);
A = A + eye(100, 'like', A);
[rowptr, colind, val] = crs_matrix(A); % This requires MSPACK
b = rand(100,1);

% Solve using default KSP solver and preconditioner
[x,flag,relres,iter,times] = mptSolveCRS(rowptr, colind, val, b);

% Solve using GMRES with Jacobi preconditioner with default options
[x,flag,relres,iter,times] = mptSolveCRS(rowptr, colind, val, b, PETSC_KSPGMRES, 0, int32(0), PETSC_PCJACOBI);

% Solve using SuperLU (assuming SuperLU was installed)
[x,flag,relres,iter,times] = mptSolveCRS(rowptr, colind, val, b, PETSC_KSPPREONLY, 0, int32(0), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);
