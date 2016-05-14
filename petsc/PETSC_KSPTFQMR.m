function val = PETSC_KSPTFQMR %#codegen
% Obtain PETSC constant KSPTFQMR

coder.inline('always');

val = petscGetObject('KSPTFQMR');
end
