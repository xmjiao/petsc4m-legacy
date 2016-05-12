function val = PETSC_MAT_IGNORE_MATRIX %#codegen
% Obtain PETSC constant MAT_IGNORE_MATRIX

coder.inline('always');

val = petscGetEnum('MAT_IGNORE_MATRIX');
end
