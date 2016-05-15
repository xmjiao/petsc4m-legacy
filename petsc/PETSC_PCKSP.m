function val = PETSC_PCKSP %#codegen
% Obtain PETSC constant PCKSP

coder.inline('always');

val = petscGetString('PCKSP');
end
