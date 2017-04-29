function type = PetscMatType(arg, wrap) %#codegen
%Map a null-terminated C string into a PETSc MatType handle
%
%  PetscMatType() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  PetscMatType(arg) or PetscMatType(arg, false) converts arg into a 
%  PETSc MatType object.
%
%  PetscMatType(arg, 'wrap') or PetscMatType(arg, true) copies the arg
%  into a MATLAB string. This should be used if the object needs to
%  be returned to MATLAB. Note that the value of the second
%  argumentmust be determined at compile time.
%
% See also PetscVecType

coder.inline('always');
coder.cinclude('petsc4m.h');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('Petsc4m:PetscMatType:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end


if nargin==1 || ~ischar(wrap) && ~wrap
    type = arg;
else
    type = m2c_strcopy(arg, 'wrap');
end
