function val = PETSC_VECVIENNACL
% Obtain PETSC constant VECVIENNACL

coder.inline('always');

val = petscGetString('VECVIENNACL');
end
