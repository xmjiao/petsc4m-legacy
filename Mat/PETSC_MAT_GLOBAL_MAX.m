function val = PETSC_MAT_GLOBAL_MAX
% Obtain PETSC constant MAT_GLOBAL_MAX

coder.inline('always');

val = petscGetEnum('MAT_GLOBAL_MAX');
end
