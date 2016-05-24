function val = PETSC_NORM_2 %#codegen
% Obtain PETSC constant NORM_2

coder.inline('always');

val = petscGetEnum('NORM_2');
end
