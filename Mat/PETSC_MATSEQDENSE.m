function val = PETSC_MATSEQDENSE
% Obtain PETSC constant MATSEQDENSE

coder.inline('always');

val = 'seqdense';end
