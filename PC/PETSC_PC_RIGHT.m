function val = PETSC_PC_RIGHT
% Obtain PETSC constant PC_RIGHT

coder.inline('always');

val = petscGetEnum('PC_RIGHT');
end
