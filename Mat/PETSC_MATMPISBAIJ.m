function val = PETSC_MATMPISBAIJ %#codegen
% Obtain PETSC constant MATMPISBAIJ

coder.inline('always');

val = petscGetString('MATMPISBAIJ');
end
