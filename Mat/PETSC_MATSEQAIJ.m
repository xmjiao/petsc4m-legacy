function val = PETSC_MATSEQAIJ
% Obtain PETSC constant MATSEQAIJ

coder.inline('always');

val = 'seqaij';end
