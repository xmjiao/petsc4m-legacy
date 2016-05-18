function obj = PETSC_NULL_REAL %#codegen
% Obtain PETSC constant NULL of type double *

coder.inline('always');

obj = petscGetObject('PETSC_NULL_REAL');
end
