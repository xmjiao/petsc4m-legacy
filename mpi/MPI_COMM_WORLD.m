function val = MPI_COMM_WORLD %#codegen
% Obtain PETSC/MPI constant MPI_COMM_WORLD

coder.inline('always');

val = petscGetObject('MPI_COMM_WORLD');
end
