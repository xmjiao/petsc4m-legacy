function val = PETSC_VECSEQVIENNACL %#codegen
% Obtain PETSC constant VECSEQVIENNACL

coder.inline('always');

val = petscGetString('VECSEQVIENNACL');
end
