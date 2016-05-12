function val = PETSC_MAT_COPY_VALUES %#codegen
% Obtain PETSC constant MAT_COPY_VALUES

coder.inline('always');

val = petscGetEnum('MAT_COPY_VALUES');
end
