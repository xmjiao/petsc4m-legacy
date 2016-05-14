function val = PETSC_PCASM %#codegen
% Obtain PETSC constant PCASM

coder.inline('always');

val = petscGetObject('PCASM');
end
