function val = PETSC_KSP_NORM_PRECONDITIONED
% Obtain PETSC constant KSP_NORM_PRECONDITIONED

coder.inline('always');

val = petscGetEnum('KSP_NORM_PRECONDITIONED');
end
