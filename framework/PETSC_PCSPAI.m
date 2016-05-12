function val = PETSC_PCSPAI %#codegen
% Obtain PETSC constant PCSPAI

coder.inline('always');

val = petscGetObject('PCSPAI');
end
