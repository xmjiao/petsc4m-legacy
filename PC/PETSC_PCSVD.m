function val = PETSC_PCSVD
% Obtain PETSC constant PCSVD

coder.inline('always');

val = 'svd';
end
