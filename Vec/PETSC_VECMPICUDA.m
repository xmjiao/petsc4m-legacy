function val = PETSC_VECMPICUDA
% Obtain PETSC constant VECMPICUDA

coder.inline('always');

val = petscGetString('VECMPICUDA');
end
