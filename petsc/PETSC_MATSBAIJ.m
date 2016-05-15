function val = PETSC_MATSBAIJ %#codegen
% Obtain PETSC constant MATSBAIJ

coder.inline('always');

val = petscGetString('MATSBAIJ');
end
