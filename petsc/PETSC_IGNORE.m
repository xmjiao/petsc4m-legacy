function val = PETSC_IGNORE %#codegen
% Obtain PETSC constant PETSC_IGNORE

coder.inline('always');

val = petscGetObject('PETSC_IGNORE');
end
