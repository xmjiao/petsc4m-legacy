function val = PETSC_PCJACOBI %#codegen
% Obtain PETSC constant PCJACOBI

coder.inline('always');

val = petscGetObject('PCJACOBI');
end
