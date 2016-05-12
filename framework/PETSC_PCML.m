function val = PETSC_PCML %#codegen
% Obtain PETSC constant PCML

coder.inline('always');

val = petscGetObject('PCML');
end
