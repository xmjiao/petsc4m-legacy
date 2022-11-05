function val = PETSC_VECCUDA
% Obtain PETSC constant VECCUDA

coder.inline('always');

val = petscGetString('VECCUDA');
end
