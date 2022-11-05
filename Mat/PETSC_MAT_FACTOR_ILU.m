function val = PETSC_MAT_FACTOR_ILU
% Obtain PETSC constant MAT_FACTOR_ILU

coder.inline('always');

val = petscGetEnum('MAT_FACTOR_ILU');
end
