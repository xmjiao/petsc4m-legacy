function val = PETSC_PCSACUSP %#codegen
% Obtain PETSC constant PCSACUSP

coder.inline('always');

val = petscGetObject('PCSACUSP');
end
