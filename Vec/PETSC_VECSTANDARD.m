function val = PETSC_VECSTANDARD
% Obtain PETSC constant VECSTANDARD

coder.inline('always');

val = petscGetString('VECSTANDARD');
end
