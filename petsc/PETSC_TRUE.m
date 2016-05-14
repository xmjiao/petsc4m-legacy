function val = PETSC_TRUE %#codegen
% Obtain PETSC constant PETSC_TRUE

coder.inline('always');

val = petscGetEnum('PETSC_TRUE');
end
