function val = PETSC_PCPBJACOBI %#codegen
% Obtain PETSC constant PCPBJACOBI

coder.inline('always');

val = petscGetString('PCPBJACOBI');
end
