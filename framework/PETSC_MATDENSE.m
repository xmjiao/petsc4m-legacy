function val = PETSC_MATDENSE %#codegen
% Obtain PETSC constant MATDENSE

coder.inline('always');

val = petscGetObject('MATDENSE');
end
