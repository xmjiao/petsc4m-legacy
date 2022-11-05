function val = PETSC_VECSEQVIENNACL
% Obtain PETSC constant VECSEQVIENNACL

coder.inline('always');

val = petscGetString('VECSEQVIENNACL');
end
