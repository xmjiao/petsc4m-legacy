function val = PETSC_MATSEQAIJCUSP %#codegen
% Obtain PETSC constant MATSEQAIJCUSP

coder.inline('always');

val = petscGetString('MATSEQAIJCUSP');
end
