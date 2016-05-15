function val = PETSC_MATSOLVERSUPERLU %#codegen
% Obtain PETSC constant MATSOLVERSUPERLU

coder.inline('always');

val = petscGetString('MATSOLVERSUPERLU');
end
