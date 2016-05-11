function val = PETSC_DEFAULT %#codegen
% Obtain PETSC constant PETSC_DEFAULT

coder.inline('always');

val = petscGetEnum('PETSC_DEFAULT');
end
