function val = PETSC_MATSOLVERUMFPACK %#codegen
% Obtain PETSC constant MATSOLVERUMFPACK

coder.inline('always');

val = petscGetString('MATSOLVERUMFPACK');
end
