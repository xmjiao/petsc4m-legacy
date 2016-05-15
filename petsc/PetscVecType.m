function type = PetscVecType(arg, opaque) %#codegen
%Map a null-terminated C string into a PETSc VecType handle
%
%  type = PetscVecType() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  type = PetscVecType(arg) or type = PetscVecType(arg, false) converts arg
%  into a PETSc VecType object.
%
%  type = PetscVecType(arg, true) copies the arg into a VecLAB string.
%  This should be used if the object needs to be returned to VecLAB.
%  Note that the value of opaque must be determined at compile time.
%
% See also PetscMatType

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('MPETSc:PetscVecType:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~opaque
    type = arg;
else
    type = m2c_strcopy(arg, opaque);
end
