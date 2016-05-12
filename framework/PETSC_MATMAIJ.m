function val = PETSC_MATMAIJ %#codegen
% Obtain PETSC constant MATMAIJ

coder.inline('always');

val = petscGetObject('MATMAIJ');
end
