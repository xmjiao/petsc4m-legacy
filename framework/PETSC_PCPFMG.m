function val = PETSC_PCPFMG %#codegen
% Obtain PETSC constant PCPFMG

coder.inline('always');

val = petscGetObject('PCPFMG');
end
