function type = PetscMatSolverType(arg, wrap) %#codegen
%Map a null-terminated C string into a PETSc MatSolverType handle
%
%  PetscMatSolverType() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  PetscMatSolverType(arg) or PetscMatSolverType(arg, false) converts arg into a
%  PETSc MatSolverType object.
%
%  PetscMatSolverType(arg, 'wrap') or PetscMatSolverType(arg, true) copies the
%  arg into a MATLAB string. This should be used if the object
%  needs to be returned to MATLAB. Note that the value of the
%  second argument must be determined at compile time.
%
% See also PetscKSPType, PetscPCType, PETSC_NATSOLVER*

coder.inline('always');
coder.cinclude('petsc4m.h');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('Petsc4m:PetscMatSolverType:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~ischar(wrap) && ~wrap
    type = arg;
else
    type = m2c_strcopy(arg, 'wrap');
end
