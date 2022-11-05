function val = PETSC_COMM_SELF
% Obtain PETSC constant PETSC_COMM_SELF

coder.inline('always');

val = petscGetObject('PETSC_COMM_SELF');
end
