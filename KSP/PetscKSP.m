function ksp = PetscKSP(varargin)
%Map an opaque object into a PETSc KSP object
%
%  PetscKSP() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument type specification for codegen.
%
%  PetscKSP(obj) or PetscKSP(obj, false) converts arg into a PETSc KSP object.
%
%  PetscKSP(arg, 'wrap') or PetscKSP(arg, true) wraps the arg into an opaque
%  object. This should be used if the object needs to be returned to MATLAB.
%
% See also PetscPC

coder.inline('always');
coder.cinclude('petsc4m.h');

ksp = m2c_opaque_obj('KSP', varargin{:});
