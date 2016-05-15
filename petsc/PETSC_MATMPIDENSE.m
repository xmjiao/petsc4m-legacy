function val = PETSC_MATMPIDENSE %#codegen
% Obtain PETSC constant MATMPIDENSE

coder.inline('always');

val = petscGetString('MATMPIDENSE');
end
