function val = PETSC_VECMPIVIENNACL
% Obtain PETSC constant VECMPIVIENNACL

coder.inline('always');

val = petscGetString('VECMPIVIENNACL');
end
