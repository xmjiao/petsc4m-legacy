function val = PETSC_VECSEQCUDA
% Obtain PETSC constant VECSEQCUDA

coder.inline('always');

val = petscGetString('VECSEQCUDA');
end
