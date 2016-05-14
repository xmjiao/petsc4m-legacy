function val = PETSC_MATAIJCUSP %#codegen
% Obtain PETSC constant MATAIJCUSP

coder.inline('always');

val = petscGetObject('MATAIJCUSP');
end
