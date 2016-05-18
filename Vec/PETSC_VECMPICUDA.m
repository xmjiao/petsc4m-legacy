function val = PETSC_VECMPICUDA %#codegen
% Obtain PETSC constant VECMPICUDA

coder.inline('always');

val = petscGetString('VECMPICUDA');
end
