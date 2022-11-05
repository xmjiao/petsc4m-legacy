function val = PETSC_MATSOLVERCUSPARSE
% Obtain PETSC constant MATSOLVERCUSPARSE

coder.inline('always');

val = 'cusparse';
end
