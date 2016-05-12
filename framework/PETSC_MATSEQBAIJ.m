function val = PETSC_MATSEQBAIJ %#codegen
% Obtain PETSC constant MATSEQBAIJ

coder.inline('always');

val = petscGetObject('MATSEQBAIJ');
end
