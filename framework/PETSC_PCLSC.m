function val = PETSC_PCLSC %#codegen
% Obtain PETSC constant PCLSC

coder.inline('always');

val = petscGetObject('PCLSC');
end
