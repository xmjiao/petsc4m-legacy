function val = PETSC_NORM_1
% Obtain PETSC constant NORM_1

coder.inline('always');

val = petscGetEnum('NORM_1');
end
