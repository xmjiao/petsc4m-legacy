function val = PETSC_MATBAIJ %#codegen
% Obtain PETSC constant MATBAIJ

coder.inline('always');

val = petscGetObject('MATBAIJ');
end
