function val = PETSC_NORM_2
% Obtain PETSC constant NORM_2

coder.inline('always');

val = petscGetEnum('NORM_2');
end
