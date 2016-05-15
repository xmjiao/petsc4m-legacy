function val = PETSC_MATSEQMAIJ %#codegen
% Obtain PETSC constant MATSEQMAIJ

coder.inline('always');

val = petscGetString('MATSEQMAIJ');
end
