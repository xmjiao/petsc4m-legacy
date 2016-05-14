function val = PETSC_KSPPREONLY %#codegen
% Obtain PETSC constant KSPPREONLY

coder.inline('always');

val = petscGetObject('KSPPREONLY');
end
