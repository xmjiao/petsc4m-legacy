function val = PETSC_MATMPIBAIJ
% Obtain PETSC constant MATMPIBAIJ

coder.inline('always');

val = 'mpibaij';end
