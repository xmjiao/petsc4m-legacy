function val = PETSC_KSPFBCGS %#codegen
% Obtain PETSC constant KSPFBCGS

coder.inline('always');

val = petscGetString('KSPFBCGS');
end
