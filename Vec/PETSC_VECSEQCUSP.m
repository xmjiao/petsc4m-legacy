function val = PETSC_VECSEQCUSP
% Obtain PETSC constant VECSEQCUSP

coder.inline('always');

val = petscGetString('VECSEQCUSP');
end
