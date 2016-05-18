function val = PETSC_MATBAIJ %#codegen
% Obtain PETSC constant MATBAIJ

coder.inline('always');

val = petscGetString('MATBAIJ');
end
