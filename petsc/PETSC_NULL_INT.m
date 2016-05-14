function obj = PETSC_NULL_INT %#codegen
% Obtain PETSC constant NULL of type int *

coder.inline('always');

obj = petscGetObject('PETSC_NULL_INT');
end
