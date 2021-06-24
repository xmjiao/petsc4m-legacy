% Set up a test matrix
A = sprand(100,100,0.3);
A = A + speye(100);
[rowptr, colind, val] = crs_matrix(A); % This requires MSPACK
b = rand(100,1);

% Solve using default KSP solver and preconditioner
[x,flag,relres,iter,reshist,times] = petscSolveCRS(rowptr, colind, val, b);

% Solve using GMRES with Jacobi preconditioner with default options
[x,flag,relres,iter,reshist,times] = petscSolveCRS(rowptr, colind, val, b, ...
    PETSC_KSPGMRES, PetscScalar(0), int32(0), PETSC_PCJACOBI);

% Solve using BiCGSTAB with Jacobi preconditioner as right preconditioner 
% with relative tolerance 1.e-10 and a maximum of 100 iterations
[x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, val, b, ...
    PETSC_KSPBCGS, 1.e-10, int32(100), PETSC_PCJACOBI, 'right');

% Solve using SuperLU (assuming SuperLU was installed)
[x,flag,relres,iter,reshist,times] = petscSolveCRS(rowptr, colind, val, b, ...
    PETSC_KSPPREONLY, 0, int32(0), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);

% Solve using BiCGSTAB with Jacobi preconditioner as right preconditioner 
% and monitor the true residual
[x,flag,relres,iter,reshis,times] = petscSolveCRS(rowptr, colind, val, b, ...
    PETSC_KSPBCGS, 1.e-10, int32(100), PETSC_PCJACOBI, 'right', ...
    PetscScalar(zeros(0, 1)), '-ksp-monitor-true-residual');
