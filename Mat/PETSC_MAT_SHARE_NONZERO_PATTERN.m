function val = PETSC_MAT_SHARE_NONZERO_PATTERN %#codegen
% Obtain PETSC constant MAT_SHARE_NONZERO_PATTERN

coder.inline('always');

val = petscGetEnum('MAT_SHARE_NONZERO_PATTERN');
end
