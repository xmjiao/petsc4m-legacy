function val = PETSC_KSPGMRES %#codegen
% Obtain PETSC constant KSPGMRES

coder.inline('always');

val = petscGetString('KSPGMRES');
end
