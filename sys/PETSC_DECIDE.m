function val = PETSC_DECIDE
% Obtain PETSC constant PETSC_DECIDE

coder.inline('always');

val = petscGetEnum('PETSC_DECIDE');
end
