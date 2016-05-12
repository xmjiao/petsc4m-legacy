function val = PETSC_PCMG %#codegen
% Obtain PETSC constant PCMG

coder.inline('always');

val = petscGetObject('PCMG');
end
