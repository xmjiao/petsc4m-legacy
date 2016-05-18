function val = PETSC_MATSOLVERCUSPARSE %#codegen
% Obtain PETSC constant MATSOLVERCUSPARSE

coder.inline('always');

val = petscGetString('MATSOLVERCUSPARSE');
end
