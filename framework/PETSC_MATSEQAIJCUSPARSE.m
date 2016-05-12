function val = PETSC_MATSEQAIJCUSPARSE %#codegen
% Obtain PETSC constant MATSEQAIJCUSPARSE

coder.inline('always');

val = petscGetObject('MATSEQAIJCUSPARSE');
end
