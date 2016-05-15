function val = PETSC_KSPPREONLY %#codegen
% Obtain PETSC constant KSPPREONLY

coder.inline('always');

val = petscGetString('KSPPREONLY');
end
