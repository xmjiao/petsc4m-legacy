function val = PETSC_PCNONE %#codegen
% Obtain PETSC constant PCNONE

coder.inline('always');

val = petscGetObject('PCNONE');
end
