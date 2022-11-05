function val = PETSC_DIFFERENT_NONZERO_PATTERN
% Obtain PETSC constant DIFFERENT_NONZERO_PATTERN

coder.inline('always');

val = petscGetEnum('DIFFERENT_NONZERO_PATTERN');
end
