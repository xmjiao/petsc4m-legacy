function obj = PETSC_NULL_VEC
% Obtain PETSC constant NULL of type Vec

coder.inline('always');

obj = petscGetObject('PETSC_NULL_VEC');
end
