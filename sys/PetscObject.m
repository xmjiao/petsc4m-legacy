function obj = PetscObject(arg, opaque) %#codegen
%Map an opaque object into a PETSc PetscObject object
%
%  obj = PetscObject() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  obj = PetscObject(arg) or obj = PetscObject(arg, false) converts arg
%  into a PETSc Object object.
%
%  obj = PetscObject(arg, true) wraps the arg into an opaque object.
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    obj = opaque_obj_type;
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ...
        ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ...
        ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC')
    m2c_error('PetscObject:WrongType', ...
        'Incorrect data type %s. Expected PetscObject.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        obj = arg;
    else
        obj = opaque_obj('PetscObject', arg);
    end
else
    obj = castdata('PetscObject', arg.data);
end
