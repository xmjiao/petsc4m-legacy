function val = PETSC_PCKSP %#codegen
% Obtain PETSC constant PCKSP

coder.inline('always');

val = petscGetObject('PCKSP');
end
