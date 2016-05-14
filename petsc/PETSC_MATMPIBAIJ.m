function val = PETSC_MATMPIBAIJ %#codegen
% Obtain PETSC constant MATMPIBAIJ

coder.inline('always');

val = petscGetObject('MATMPIBAIJ');
end
