function val = PETSC_MATSEQMAIJ
% Obtain PETSC constant MATSEQMAIJ

coder.inline('always');

val = 'seqmaij';end
