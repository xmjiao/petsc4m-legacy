function val = PETSC_NORM_INFINITY
% Obtain PETSC constant NORM_INFINITY

coder.inline('always');

val = petscGetEnum('NORM_INFINITY');
end
