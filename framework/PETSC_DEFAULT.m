function val = petscDEFAULT %#codegen
% Obtain PETSC constant PETSC_DEFAULT

coder.inline('always');

val = petscGetEnum('PETSC_DEFAULT');
end
