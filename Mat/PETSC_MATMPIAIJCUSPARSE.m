function val = PETSC_MATMPIAIJCUSPARSE %#codegen
% Obtain PETSC constant MATMPIAIJCUSPARSE

coder.inline('always');

val = petscGetString('MATMPIAIJCUSPARSE');
end
