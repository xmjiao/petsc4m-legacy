function val = PETSC_MATSOLVERCHOLMOD
% Obtain PETSC constant MATSOLVERCHOLMOD

coder.inline('always');

val = 'cholmod';
end
