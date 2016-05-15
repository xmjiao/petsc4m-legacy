function val = PETSC_MATMPIADJ %#codegen
% Obtain PETSC constant MATMPIADJ

coder.inline('always');

val = petscGetString('MATMPIADJ');
end
