function nullsp = PetscMatNullSpace(varargin) %#codegen
%Map an opaque object into a PETSc MatNullSpace object
%
%  PetscMatNullSpace() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument type specification for codegen.
%
%  PetscMatNullSpace(obj) or PetscMatNullSpace(obj, false) converts
%  arg into a PETSc MatNullSpace object.
%
%  PetscMatNullSpace(arg, 'wrap') or PetscMatNullSpace(arg, true)
%  wraps the arg into an opaque object. This should be used if the 
%  opaque object needs to be returned to MATLAB.
%
% See also petscMatNullSpaceCreate

coder.inline('always');
coder.cinclude('petsc4m.h');

nullsp = m2c_opaque_obj('MatNullSpace', varargin{:});
