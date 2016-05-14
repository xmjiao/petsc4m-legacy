function val = PETSC_PCGALERKIN %#codegen
% Obtain PETSC constant PCGALERKIN

coder.inline('always');

val = petscGetObject('PCGALERKIN');
end
