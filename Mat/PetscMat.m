function mat = PetscMat(varargin) %#codegen
%Map an opaque object into a PETSc Mat object
%
%  PetscMat() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument type specification for codegen.
%
%  PetscMat(arg) or PetscMat(arg, false) converts arg into a PETSc Mat object.
%
%  PetscMat(arg, 'wrap') or PetscMat(arg, true) wraps the arg into an opaque 
%  object. This should be used if the object needs to be returned to MATLAB.
%
% See also PetscVec

coder.inline('always');
coder.cinclude('mpetsc.h');

mat = m2c_opaque_obj('Mat', varargin{:});
