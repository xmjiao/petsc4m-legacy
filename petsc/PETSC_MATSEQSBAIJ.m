function val = PETSC_MATSEQSBAIJ %#codegen
% Obtain PETSC constant MATSEQSBAIJ

coder.inline('always');

val = petscGetString('MATSEQSBAIJ');
end
