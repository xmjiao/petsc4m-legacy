function val = PETSC_VECMPI
% Obtain PETSC constant VECMPI

coder.inline('always');

val = petscGetString('VECMPI');
end
