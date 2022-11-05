function val = PETSC_PCCHOLESKY
% Obtain PETSC constant PCCHOLESKY

coder.inline('always');

val = 'cholesky';
end
