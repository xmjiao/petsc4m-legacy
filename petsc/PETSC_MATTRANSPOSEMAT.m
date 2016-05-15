function val = PETSC_MATTRANSPOSEMAT %#codegen
% Obtain PETSC constant MATTRANSPOSEMAT

coder.inline('always');

val = petscGetString('MATTRANSPOSEMAT');
end
