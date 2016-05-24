function obj = PetscObject(arg, wrap) %#codegen
%Map an opaque object into a PETSc PetscObject object
%
%  obj = PetscObject() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument
%  specification for codegen.
%
%  obj = PetscObject(arg) or obj = PetscObject(arg, false) converts
%  arg into a PETSc Object object.
%
%  obj = PetscObject(arg, 'wrap') or obj = PetscObject(arg, true)
%  wraps the arg into an opaque object. This should be used if the 
%  object needs to be returned to MATLAB. Note that the value of 
%  opaque must be determined at compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    obj = m2c_opaque_type;
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ...
        ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ...
        ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC')
    m2c_error('PetscObject:WrongType', ...
        'Incorrect data type %s. Expected PetscObject.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ischar(wrap) || ~wrap
        obj = coder.opaque('PetscObject');
        obj = coder.ceval('(PetscObject)', arg);
    else
        obj = m2c_opaque_obj('PetscObject', arg, 'wrap');
    end
else
    obj = castdata('PetscObject', arg.data);
end
