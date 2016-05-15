function val = PETSC_MAT_FACTOR_LU %#codegen
% Obtain PETSC constant MAT_FACTOR_LU

coder.inline('always');

val = petscGetString('MAT_FACTOR_LU');
end
