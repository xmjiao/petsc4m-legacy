function val = PETSC_MATMPIBAIJ %#codegen
% Obtain PETSC constant MATMPIBAIJ

coder.inline('always');

val = petscGetString('MATMPIBAIJ');
end
