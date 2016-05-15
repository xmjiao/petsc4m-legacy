function val = PETSC_MATSOLVERCHOLMOD %#codegen
% Obtain PETSC constant MATSOLVERCHOLMOD

coder.inline('always');

val = petscGetString('MATSOLVERCHOLMOD');
end
