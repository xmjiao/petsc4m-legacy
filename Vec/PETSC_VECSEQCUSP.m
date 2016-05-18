function val = PETSC_VECSEQCUSP %#codegen
% Obtain PETSC constant VECSEQCUSP

coder.inline('always');

val = petscGetString('VECSEQCUSP');
end
