function type = PetscVecType(arg, wrap) %#codegen
%Map a null-terminated C string into a PETSc VecType handle
%
%  PetscVecType() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  PetscVecType(arg) or PetscVecType(arg, false) converts arg into a
%  PETSc VecType object.
%
%  PetscVecType(arg, 'wrap') or PetscVecType(arg, true) copies the
%  arg into a VecLAB string. This should be used if the object
%  needs to be returned to VecLAB. Note that the value of the
%  second argument must be determined at compile time.
%
% See also PetscMatType

coder.inline('always');
coder.cinclude('petsc4m.h');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('Petsc4m:PetscVecType:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~ischar(wrap) && ~wrap
    type = arg;
else
    type = m2c_strcopy(arg, 'wrap');
end
