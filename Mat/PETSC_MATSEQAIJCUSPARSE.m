function val = PETSC_MATSEQAIJCUSPARSE %#codegen
% Obtain PETSC constant MATSEQAIJCUSPARSE

coder.inline('always');

val = petscGetString('MATSEQAIJCUSPARSE');
end
