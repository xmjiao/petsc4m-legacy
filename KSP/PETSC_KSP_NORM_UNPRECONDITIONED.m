function val = PETSC_KSP_NORM_UNPRECONDITIONED
% Obtain PETSC constant KSP_NORM_UNPRECONDITIONED

coder.inline('always');

val = petscGetEnum('KSP_NORM_UNPRECONDITIONED');
end
