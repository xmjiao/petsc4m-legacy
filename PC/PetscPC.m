function pc = PetscPC(varargin)
%Map an opaque object into a PETSc PC object
%
%  PetscPC() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument type specification for codegen.
%
%  PetscPC(obj) or PetscPC(obj, false) converts arg into a PETSc PC object.
%
%  PetscPC(arg, 'wrap') or PetscPC(obj, true) wraps the arg into an opaque
%  object. This should be used if the object needs to be returned to MATLAB.
%
% See also PetscPC

coder.inline('always');
coder.cinclude('petsc4m.h');

pc = m2c_opaque_obj('PC', varargin{:});
