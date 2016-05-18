function val = PETSC_NORM_INFINITY %#codegen
% Obtain PETSC constant NORM_INFINITY

coder.inline('always');

val = petscGetEnum('NORM_INFINITY');
end
