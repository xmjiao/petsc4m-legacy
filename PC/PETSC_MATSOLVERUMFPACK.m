function val = PETSC_MATSOLVERUMFPACK
% Obtain PETSC constant MATSOLVERUMFPACK

coder.inline('always');

val = 'umfpack';
end
