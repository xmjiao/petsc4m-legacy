function val = PETSC_KSPCG %#codegen
% Obtain PETSC constant KSPCG

coder.inline('always');

val = petscGetObject('KSPCG');
end
