function val = PETSC_FALSE
% Obtain PETSC constant PETSC_FALSE

coder.inline('always');

val = petscGetEnum('PETSC_FALSE');
end
