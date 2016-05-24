function val = PETSC_PC_LEFT %#codegen
% Obtain PETSC constant PC_LEFT

coder.inline('always');

val = petscGetEnum('PC_LEFT');
end
