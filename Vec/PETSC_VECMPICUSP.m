function val = PETSC_VECMPICUSP
% Obtain PETSC constant VECMPICUSP

coder.inline('always');

val = petscGetString('VECMPICUSP');
end
