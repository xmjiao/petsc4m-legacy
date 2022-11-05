function val = PETSC_COMM_WORLD
% Obtain PETSC constant PETSC_COMM_WORLD

coder.inline('always');

val = petscGetObject('PETSC_COMM_WORLD');
end
