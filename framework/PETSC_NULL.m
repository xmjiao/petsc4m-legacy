function val = PETSC_NULL %#codegen
% Obtain PETSC constant PETSC_NULL

coder.inline('always');
val = coder.opaque('void *', 'NULL');
end
