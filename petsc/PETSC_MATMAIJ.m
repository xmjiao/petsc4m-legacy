function val = PETSC_MATMAIJ %#codegen
% Obtain PETSC constant MATMAIJ

coder.inline('always');

val = petscGetString('MATMAIJ');
end
