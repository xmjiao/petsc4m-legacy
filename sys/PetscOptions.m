function opts = PetscOptions(varargin)
%Map an opaque object into a PETSc Options object
%
%  PetscOptions() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  PetscOptions(obj) or PetscOptions(obj, false) converts obj into 
%  a PETSc Options object.
%
%  PetscOptions(obj, 'wrap') or PetscOptions(obj, true) wraps the
%  obj into an opaque object. This should be used if the opaque
%  object needs to be returned to MATLAB.
%
% See also PetscMat

coder.inline('always');
coder.cinclude('petsc4m.h');

opts = m2c_opaque_obj('PetscOptions', varargin{:});
