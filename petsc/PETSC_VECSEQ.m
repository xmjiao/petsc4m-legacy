function val = PETSC_VECSEQ %#codegen
% Obtain PETSC constant VECSEQ

coder.inline('always');

val = petscGetString('VECSEQ');
end
