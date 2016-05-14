function val = PETSC_FALSE %#codegen
% Obtain PETSC constant PETSC_FALSE

coder.inline('always');

val = petscGetEnum('PETSC_FALSE');
end
