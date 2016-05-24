function val = PETSC_PC_RIGHT %#codegen
% Obtain PETSC constant PC_RIGHT

coder.inline('always');

val = petscGetEnum('PC_RIGHT');
end
