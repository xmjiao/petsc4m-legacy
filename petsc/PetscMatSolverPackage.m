function type = PetscMatSolverPackage(arg, opaque) %#codegen
%Map a null-terminated C string into a PETSc MatSolverPackage handle
%
%  type = PetscMatSolverPackage() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  type = PetscMatSolverPackage(arg) or 
%  type = PetscMatSolverPackage(arg, false) converts arg into a 
%    PETSc MatSolverPackage object.
%
%  type = PetscMatSolverPackage(arg, true) copies the arg into a MATLAB string.
%  This should be used if the object needs to be returned to MATLAB.
%  Note that the value of opaque must be determined at compile time.
%
% See also PetscVecType

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('MPETSc:PetscMatSolverPackage:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~opaque
    type = arg;
else
    type = m2c_strcopy(arg, opaque);
end
