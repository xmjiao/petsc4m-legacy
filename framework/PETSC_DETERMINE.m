function val = petscDETERMINE %#codegen
% Obtain PETSC constant PETSC_DETERMINE

coder.inline('always');

val = petscGetEnum('PETSC_DETERMINE');
end
