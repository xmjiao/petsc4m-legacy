function val = PETSC_MATSAME %#codegen
% Obtain PETSC constant MATSAME

coder.inline('always');

val = petscGetObject('MATSAME');
end
