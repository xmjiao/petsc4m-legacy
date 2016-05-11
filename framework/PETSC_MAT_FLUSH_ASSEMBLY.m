function val = PETSC_MAT_FLUSH_ASSEMBLY %#codegen
% Obtain PETSC constant MAT_FLUSH_ASSEMBLY

coder.inline('always');

val = petscGetEnum('MAT_FLUSH_ASSEMBLY');
end
