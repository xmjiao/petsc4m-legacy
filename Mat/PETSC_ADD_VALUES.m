function val = PETSC_ADD_VALUES
% Obtain PETSC constant ADD_VALUES

coder.inline('always');

val = petscGetEnum('ADD_VALUES');
end
