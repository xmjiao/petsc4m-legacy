function val = PETSC_PCHYPRE %#codegen
% Obtain PETSC constant PCHYPRE

coder.inline('always');

val = petscGetString('PCHYPRE');
end
