function rmv = PetscMatNullSpaceRemoveFunc(varargin) %#codegen
%Map an opaque object into a PETSc MatNullSpaceRemoveFunc object
%
%  PetscMatNullSpaceRemoveFunc() simply returns a definition of the 
%  m2c_opaque_type, suitable in the argument type specification for codegen.
%
%  PetscMatNullSpaceRemoveFunc(obj) or
%  PetscMatNullSpaceRemoveFunc(obj, false) converts arg into a PETSc 
%  MatNullSpaceRemoveFunc object.
%
%  PetscMatNullSpaceRemoveFunc(arg, 'wrap') or
%  PetscMatNullSpaceRemoveFunc(arg, true) wraps the arg into an opaque object. 
%  This should be used if the opaque object needs to be returned to MATLAB.
%
% See also petscMatNullSpaceRemoveFuncCreate

coder.inline('always');
coder.cinclude('petsc4m.h');

rmv = m2c_opaque_obj('MatNullSpaceRemoveFunc', varargin{:});
