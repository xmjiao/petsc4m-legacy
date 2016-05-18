function val = PETSC_PCSVD %#codegen
% Obtain PETSC constant PCSVD

coder.inline('always');

val = petscGetString('PCSVD');
end
