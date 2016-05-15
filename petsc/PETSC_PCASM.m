function val = PETSC_PCASM %#codegen
% Obtain PETSC constant PCASM

coder.inline('always');

val = petscGetString('PCASM');
end
