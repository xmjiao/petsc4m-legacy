function ksp = PetscKSP(arg, opaque) %#codegen
%Map an opaque object into a PETSc KSP object
%
%  ksp = PetscKSP() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument
%  specification for codegen.
%
%  ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg
%  into a PETSc KSP object.
%
%  ksp = PetscKSP(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscPC

coder.inline('always');

if nargin==0 && isempty(coder.target)
    ksp = m2c_opaque_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'KSP')
    m2c_error('PetscKSP:WrongType', ...
        'Incorrect data type %s. Expected KSP.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        ksp = arg;
    else
        ksp = m2c_opaque_obj('KSP', arg);
    end
else
    ksp = castdata('KSP', arg.data);
end
