function type = PetscKSPType(arg, opaque) %#codegen
%Map a null-terminated C string into a PETSc KSPType handle
%
%  type = PetscKSPType() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  type = PetscKSPType(arg) or type = PetscKSPType(arg, false) converts arg
%  into a PETSc KSPType object.
%
%  type = PetscKSPType(arg, true) copies the arg into a MATLAB string.
%  This should be used if the object needs to be returned to MATLAB.
%  Note that the value of opaque must be determined at compile time.
%
% See also PetscPCType, PETSC_KSP*

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('MPETSc:PetscKSPType:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~opaque
    type = arg;
else
    type = m2c_strcopy(arg, opaque);
end
