function val = PETSC_MATMPIMAIJ
% Obtain PETSC constant MATMPIMAIJ

coder.inline('always');

val = 'mpimaij';end
