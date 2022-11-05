function val = PETSC_MAT_DO_NOT_COPY_VALUES
% Obtain PETSC constant MAT_DO_NOT_COPY_VALUES

coder.inline('always');

val = petscGetEnum('MAT_DO_NOT_COPY_VALUES');
end
