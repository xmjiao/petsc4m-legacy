function val = PETSC_KSP_NORM_NONE %#codegen
% Obtain PETSC constant KSP_NORM_NONE

coder.inline('always');

val = petscGetEnum('KSP_NORM_NONE');
end
