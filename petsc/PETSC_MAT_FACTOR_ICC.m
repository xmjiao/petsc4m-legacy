function val = PETSC_MAT_FACTOR_ICC %#codegen
% Obtain PETSC constant MAT_FACTOR_ICC

coder.inline('always');

val = petscGetString('MAT_FACTOR_ICC');
end
