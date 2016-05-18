function val = PETSC_MAT_FACTOR_ILU %#codegen
% Obtain PETSC constant MAT_FACTOR_ILU

coder.inline('always');

val = petscGetString('MAT_FACTOR_ILU');
end
