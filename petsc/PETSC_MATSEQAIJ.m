function val = PETSC_MATSEQAIJ %#codegen
% Obtain PETSC constant MATSEQAIJ

coder.inline('always');

val = petscGetObject('MATSEQAIJ');
end
