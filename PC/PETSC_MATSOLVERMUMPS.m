function val = PETSC_MATSOLVERMUMPS %#codegen
% Obtain PETSC constant PETSC_MATSOLVERMUMPS

coder.inline('always');

val = petscGetString('MATSOLVERMUMPS');
end
