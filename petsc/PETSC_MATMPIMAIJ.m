function val = PETSC_MATMPIMAIJ %#codegen
% Obtain PETSC constant MATMPIMAIJ

coder.inline('always');

val = petscGetString('MATMPIMAIJ');
end
