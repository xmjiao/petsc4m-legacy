function val = PETSC_MAT_FACTOR_CHOLESKY
% Obtain PETSC constant MAT_FACTOR_CHOLESKY

coder.inline('always');

val = petscGetEnum('MAT_FACTOR_CHOLESKY');
end
