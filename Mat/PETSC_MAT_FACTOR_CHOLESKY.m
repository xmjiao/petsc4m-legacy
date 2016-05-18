function val = PETSC_MAT_FACTOR_CHOLESKY %#codegen
% Obtain PETSC constant MAT_FACTOR_CHOLESKY

coder.inline('always');

val = petscGetString('MAT_FACTOR_CHOLESKY');
end
