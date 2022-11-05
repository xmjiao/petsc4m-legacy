function val = PETSC_MAT_FACTOR_ICC
% Obtain PETSC constant MAT_FACTOR_ICC

coder.inline('always');

val = petscGetEnum('MAT_FACTOR_ICC');
end
