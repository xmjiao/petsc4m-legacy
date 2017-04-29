function vec = PetscVec(varargin) %#codegen
%Map an opaque object into a PETSc Vec object
%
%  PetscVec() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  PetscVec(obj) or PetscVec(false) converts obj into a PETSc Vec object.
%
%  PetscVec(obj, 'wrap') or PetscVec(obj, true) wraps the obj into an opaque 
%  object. This should be used if the opaque object needs to be returned to MATLAB.
%
% See also PetscMat

coder.inline('always');
coder.cinclude('petsc4m.h');

vec = m2c_opaque_obj('Vec', varargin{:});
