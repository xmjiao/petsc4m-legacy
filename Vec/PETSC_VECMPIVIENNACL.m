function val = PETSC_VECMPIVIENNACL %#codegen
% Obtain PETSC constant VECMPIVIENNACL

coder.inline('always');

val = petscGetString('VECMPIVIENNACL');
end
