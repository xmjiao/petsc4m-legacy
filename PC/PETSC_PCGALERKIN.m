function val = PETSC_PCGALERKIN %#codegen
% Obtain PETSC constant PCGALERKIN

coder.inline('always');

val = petscGetString('PCGALERKIN');
end
