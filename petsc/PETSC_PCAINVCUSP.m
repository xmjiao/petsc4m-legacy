function val = PETSC_PCAINVCUSP %#codegen
% Obtain PETSC constant PCAINVCUSP

coder.inline('always');

val = petscGetObject('PCAINVCUSP');
end
