function val = PETSC_VECSHARED
% Obtain PETSC constant VECSHARED

coder.inline('always');

val = petscGetString('VECSHARED');
end
