function val = PETSC_PCILU %#codegen
% Obtain PETSC constant PCILU

coder.inline('always');

val = petscGetString('PCILU');
end
