function val = PETSC_KSP_NORM_NONE
% Obtain PETSC constant KSP_NORM_NONE

coder.inline('always');

val = petscGetEnum('KSP_NORM_NONE');
end
