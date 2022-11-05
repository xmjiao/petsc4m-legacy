function val = PETSC_KSPGMRES
% Obtain PETSC constant KSPGMRES

coder.inline('always');

val = 'gmres';
end
