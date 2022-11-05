function val = PETSC_MATMPIAIJ
% Obtain PETSC constant MATMPIAIJ

coder.inline('always');

val = 'mpiaij';end
