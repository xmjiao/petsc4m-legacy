function val = PETSC_MATMPIAIJCUSP %#codegen
% Obtain PETSC constant MATMPIAIJCUSP

coder.inline('always');

val = petscGetString('MATMPIAIJCUSP');
end
