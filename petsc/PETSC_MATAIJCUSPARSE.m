function val = PETSC_MATAIJCUSPARSE %#codegen
% Obtain PETSC constant MATAIJCUSPARSE

coder.inline('always');

val = petscGetString('MATAIJCUSPARSE');
end
