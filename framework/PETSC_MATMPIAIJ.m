function val = PETSC_MATMPIAIJ %#codegen
% Obtain PETSC constant MATMPIAIJ

coder.inline('always');

val = petscGetObject('MATMPIAIJ');
end
