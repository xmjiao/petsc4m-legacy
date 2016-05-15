function val = PETSC_VECNEST %#codegen
% Obtain PETSC constant VECNEST

coder.inline('always');

val = petscGetString('VECNEST');
end
