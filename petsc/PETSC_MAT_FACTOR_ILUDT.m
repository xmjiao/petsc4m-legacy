function val = PETSC_MAT_FACTOR_ILUDT %#codegen
% Obtain PETSC constant MAT_FACTOR_ILUDT

coder.inline('always');

val = petscGetString('MAT_FACTOR_ILUDT');
end
