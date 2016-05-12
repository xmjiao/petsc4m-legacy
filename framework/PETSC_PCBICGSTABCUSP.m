function val = PETSC_PCBICGSTABCUSP %#codegen
% Obtain PETSC constant PCBICGSTABCUSP

coder.inline('always');

val = petscGetObject('PCBICGSTABCUSP');
end
