function val = MPI_COMM_SELF %#codegen
% Obtain PETSC/MPI constant MPI_COMM_SELF

coder.inline('always');

val = petscGetObject('MPI_COMM_SELF');
end
