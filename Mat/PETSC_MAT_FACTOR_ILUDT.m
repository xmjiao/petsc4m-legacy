function val = PETSC_MAT_FACTOR_ILUDT
% Obtain PETSC constant MAT_FACTOR_ILUDT

coder.inline('always');

val = petscGetEnum('MAT_FACTOR_ILUDT');
end
