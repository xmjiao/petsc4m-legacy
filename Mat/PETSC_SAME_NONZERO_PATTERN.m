function val = PETSC_SAME_NONZERO_PATTERN
% Obtain PETSC constant SAME_NONZERO_PATTERN

coder.inline('always');

val = petscGetEnum('SAME_NONZERO_PATTERN');
end
