function val = PETSC_NORM_FROBENIUS
% Obtain PETSC constant NORM_FROBENIUS

coder.inline('always');

val = petscGetEnum('NORM_FROBENIUS');
end
