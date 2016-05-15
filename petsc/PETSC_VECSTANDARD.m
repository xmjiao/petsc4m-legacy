function val = PETSC_VECSTANDARD %#codegen
% Obtain PETSC constant VECSTANDARD

coder.inline('always');

val = petscGetString('VECSTANDARD');
end
