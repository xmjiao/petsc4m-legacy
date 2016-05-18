function val = PETSC_PCSOR %#codegen
% Obtain PETSC constant PCSOR

coder.inline('always');

val = petscGetString('PCSOR');
end
