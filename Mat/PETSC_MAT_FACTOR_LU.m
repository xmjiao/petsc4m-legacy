function val = PETSC_MAT_FACTOR_LU
% Obtain PETSC constant MAT_FACTOR_LU

coder.inline('always');

val = petscGetEnum('MAT_FACTOR_LU');
end
