function val = PETSC_INSERT_VALUES %#codegen
% Obtain PETSC constant INSERT_VALUES

coder.inline('always');

val = petscGetEnum('INSERT_VALUES');
end
