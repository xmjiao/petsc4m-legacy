function val = PETSC_KSPMINRES %#codegen
% Obtain PETSC constant KSPMINRES

coder.inline('always');

val = petscGetObject('KSPMINRES');
end
