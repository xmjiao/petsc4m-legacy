function val = PETSC_VECCUDA %#codegen
% Obtain PETSC constant VECCUDA

coder.inline('always');

val = petscGetString('VECCUDA');
end
