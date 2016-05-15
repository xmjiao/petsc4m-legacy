function val = PETSC_KSPLSQR %#codegen
% Obtain PETSC constant KSPLSQR

coder.inline('always');

val = petscGetString('KSPLSQR');
end
