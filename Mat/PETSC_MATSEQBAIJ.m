function val = PETSC_MATSEQBAIJ %#codegen
% Obtain PETSC constant MATSEQBAIJ

coder.inline('always');

val = petscGetString('MATSEQBAIJ');
end
