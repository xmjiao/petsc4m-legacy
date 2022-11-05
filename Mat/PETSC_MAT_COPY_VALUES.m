function val = PETSC_MAT_COPY_VALUES
% Obtain PETSC constant MAT_COPY_VALUES

coder.inline('always');

val = petscGetEnum('MAT_COPY_VALUES');
end
