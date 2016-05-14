function val = PETSC_MAT_GLOBAL_SUM %#codegen
% Obtain PETSC constant MAT_GLOBAL_SUM

coder.inline('always');

val = petscGetEnum('MAT_GLOBAL_SUM');
end
