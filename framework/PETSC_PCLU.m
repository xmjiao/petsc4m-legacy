function val = PETSC_PCLU %#codegen
% Obtain PETSC constant PCLU

coder.inline('always');

val = petscGetObject('PCLU');
end
