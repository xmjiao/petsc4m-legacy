function type = MatType(arg, opaque) %#codegen
%Map an opaque object into a PETSc MatType object
%
%  type = MatType() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  type = MatType(arg) or type = MatType(arg, false) converts arg
%  into a PETSc MatType object.
%
%  type = MatType(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscVec, PetscVecType

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type =opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'MatType')
    m2c_error('MatType:WrongType', ...
        'Incorrect data type %s. Expected MatType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        type =arg;
    else
        type =opaque_obj('MatType', arg);
    end
else
    type =castdata('MatType', arg.data);
end
