function val = PETSC_VECMPI %#codegen
% Obtain PETSC constant VECMPI

coder.inline('always');

val = petscGetString('VECMPI');
end
