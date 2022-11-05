function obj = PETSC_NULL_OPTIONS
% Obtain PETSC constant NULL of type PetscOptions

coder.inline('always');

obj = petscGetObject('PETSC_NULL_OPTIONS');
end
