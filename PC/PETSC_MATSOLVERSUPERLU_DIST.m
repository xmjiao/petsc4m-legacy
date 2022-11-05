function val = PETSC_MATSOLVERSUPERLU_DIST
% Obtain PETSC constant MATSOLVERSUPERLU_DIST

coder.inline('always');

val = 'superlu_dist';
end
