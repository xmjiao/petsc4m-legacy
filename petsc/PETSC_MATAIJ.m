function val = PETSC_MATAIJ %#codegen
% Obtain PETSC constant MATAIJ

coder.inline('always');

val = petscGetString('MATAIJ');
end
