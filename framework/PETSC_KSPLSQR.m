function val = PETSC_KSPLSQR %#codegen
% Obtain PETSC constant KSPLSQR

coder.inline('always');

val = petscGetObject('KSPLSQR');
end
