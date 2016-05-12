function val = PETSC_KSPBCGS %#codegen
% Obtain PETSC constant KSPBCGS

coder.inline('always');

val = petscGetObject('KSPBCGS');
end
