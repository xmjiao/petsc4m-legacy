function val = PETSC_PCGAMG %#codegen
% Obtain PETSC constant PCGAMG

coder.inline('always');

val = petscGetObject('PCGAMG');
end
