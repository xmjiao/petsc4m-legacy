function val = PETSC_VECVIENNACL %#codegen
% Obtain PETSC constant VECVIENNACL

coder.inline('always');

val = petscGetString('VECVIENNACL');
end
