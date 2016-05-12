function val = PETSC_SUBSET_NONZERO_PATTERN %#codegen
% Obtain PETSC constant SUBSET_NONZERO_PATTERN

coder.inline('always');

val = petscGetEnum('SUBSET_NONZERO_PATTERN');
end
