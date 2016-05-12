function val = PETSC_PCCHOLESKY %#codegen
% Obtain PETSC constant PCCHOLESKY

coder.inline('always');

val = petscGetObject('PCCHOLESKY');
end
