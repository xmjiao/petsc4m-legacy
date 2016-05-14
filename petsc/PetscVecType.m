function type = VecType(arg, opaque) %#codegen
%Map an opaque object into a PETSc VecType object
%
%  type = VecType() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  type = VecType(arg) or type = VecType(arg, false) converts arg
%  into a PETSc VecType object.
%
%  type = VecType(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMatType

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type =opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'VecType')
    m2c_error('VecType:WrongType', ...
        'Incorrect data type %s. Expected VecType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        type =arg;
    else
        type =opaque_obj('VecType', arg);
    end
else
    type =castdata('VecType', arg.data);
end
