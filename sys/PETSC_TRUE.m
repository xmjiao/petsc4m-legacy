function val = PETSC_TRUE
% Obtain PETSC constant PETSC_TRUE

coder.inline('always');

val = petscGetEnum('PETSC_TRUE');
end
