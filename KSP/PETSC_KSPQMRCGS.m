function val = PETSC_KSPQMRCGS %#codegen
% Obtain PETSC constant KSPFQMRCGS

coder.inline('always');

val = petscGetString('KSPFBCGS');
end
