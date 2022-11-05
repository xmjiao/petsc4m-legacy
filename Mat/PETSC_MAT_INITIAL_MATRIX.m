function val = PETSC_MAT_INITIAL_MATRIX
% Obtain PETSC constant MAT_INITIAL_MATRIX

coder.inline('always');

val = petscGetEnum('MAT_INITIAL_MATRIX');
end
