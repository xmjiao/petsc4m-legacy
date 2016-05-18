function val = PETSC_IGNORE %#codegen
% Obtain PETSC constant PETSC_IGNORE

coder.inline('always');

val = petscGetString('PETSC_IGNORE');
end
