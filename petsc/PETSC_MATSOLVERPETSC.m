function val = PETSC_MATSOLVERPETSC %#codegen
% Obtain PETSC constant MATSOLVERPETSC

coder.inline('always');

val = petscGetString('MATSOLVERPETSC');
end
