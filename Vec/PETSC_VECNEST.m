function val = PETSC_VECNEST
% Obtain PETSC constant VECNEST

coder.inline('always');

val = petscGetString('VECNEST');
end
