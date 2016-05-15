function val = PETSC_VECSHARED %#codegen
% Obtain PETSC constant VECSHARED

coder.inline('always');

val = petscGetString('VECSHARED');
end
