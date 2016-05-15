function val = PETSC_VECMPICUSP %#codegen
% Obtain PETSC constant VECMPICUSP

coder.inline('always');

val = petscGetString('VECMPICUSP');
end
