function val = PETSC_MATMPIMAIJ %#codegen
% Obtain PETSC constant MATMPIMAIJ

coder.inline('always');

val = petscGetObject('MATMPIMAIJ');
end
