function type = PetscPCType(arg, opaque) %#codegen
%Map an opaque object into a PETSc PCType object
%
%  type = PetscPCType() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  type = PetscPCType(arg) or type = PetscPCType(arg, false) converts arg
%  into a PETSc PCType object.
%
%  type = PetscPCType(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'PCType')
    m2c_error('PetscPCType:WrongType', ...
        'Incorrect data type %s. Expected PCType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        type = arg;
    else
        type = opaque_obj('PCType', arg);
    end
else
    type = castdata('PCType', arg.data);
end
