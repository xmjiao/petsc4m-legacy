function val = PETSC_MAT_REUSE_MATRIX %#codegen
% Obtain PETSC constant MAT_REUSE_MATRIX

coder.inline('always');

val = petscGetEnum('MAT_REUSE_MATRIX');
end
