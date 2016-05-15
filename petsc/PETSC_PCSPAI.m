function val = PETSC_PCSPAI %#codegen
% Obtain PETSC constant PCSPAI

coder.inline('always');

val = petscGetString('PCSPAI');
end
