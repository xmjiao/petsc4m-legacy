function val = PETSC_PCSOR %#codegen
% Obtain PETSC constant PCSOR

coder.inline('always');

val = petscGetObject('PCSOR');
end
