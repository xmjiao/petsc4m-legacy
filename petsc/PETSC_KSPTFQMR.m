function val = PETSC_KSPTFQMR %#codegen
% Obtain PETSC constant KSPTFQMR

coder.inline('always');

val = petscGetString('KSPTFQMR');
end
