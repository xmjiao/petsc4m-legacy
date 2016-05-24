function type = PetscMatSolverPackage(arg, wrap) %#codegen
%Map a null-terminated C string into a PETSc MatSolverPackage handle
%
%  type = PetscMatSolverPackage() simply returns a definition of a string,
%  suitable in the argument specification for codegen.
%
%  PetscMatSolverPackage(arg) or PetscMatSolverPackage(arg, false) 
%  converts arg into a PETSc MatSolverPackage object.
%
%  PetscMatSolverPackage(arg, 'wrap') or PetscMatSolverPackage(arg,
%  true) copies the arg into a VecLAB string. This should be used 
%  if the object needs to be returned to VecLAB. Note that the value of 
%  the second argument must be determined at compile time.
%
% See also PetscKSPType, PetscPCType, PETSC_MATSOLVER*

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = coder.typeof(char(0), [1, inf]);
    return;
end

if isempty(coder.target) && ~ischar(arg)
    m2c_error('MPETSc:PetscMatSolverPackage:WrongType', ...
        'Incorrect data type of argument. Expected a string.');
end

if nargin==1 || ~ischar(wrap) && ~wrap
    type = arg;
else
    type = m2c_strcopy(arg, 'wrap');
end
