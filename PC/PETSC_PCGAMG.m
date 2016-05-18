function val = PETSC_PCGAMG %#codegen
% Obtain PETSC constant PCGAMG

coder.inline('always');

val = petscGetString('PCGAMG');
end
