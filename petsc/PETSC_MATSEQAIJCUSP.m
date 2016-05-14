function val = PETSC_MATSEQAIJCUSP %#codegen
% Obtain PETSC constant MATSEQAIJCUSP

coder.inline('always');

val = petscGetObject('MATSEQAIJCUSP');
end
