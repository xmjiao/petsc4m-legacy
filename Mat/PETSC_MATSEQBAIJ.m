function val = PETSC_MATSEQBAIJ
% Obtain PETSC constant MATSEQBAIJ

coder.inline('always');

val = 'seqbaij';end
