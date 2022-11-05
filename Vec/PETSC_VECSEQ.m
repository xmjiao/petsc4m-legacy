function val = PETSC_VECSEQ
% Obtain PETSC constant VECSEQ

coder.inline('always');

val = petscGetString('VECSEQ');
end
