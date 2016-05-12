function val = PETSC_MATAIJ %#codegen
% Obtain PETSC constant MATAIJ

coder.inline('always');

val = petscGetObject('MATAIJ');
end
