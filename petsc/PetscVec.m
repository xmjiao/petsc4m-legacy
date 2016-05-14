function vec = PetscVec(arg, opaque) %#codegen
%Map an opaque object into a PETSc Vec object
%
%  vec = PetscVec() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg
%  into a PETSc Vec object.
%
%  vec = PetscVec(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    vec = opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'Vec')
    m2c_error('PetscVec:WrongType', ...
        'Incorrect data type %s. Expected Vec.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        vec = arg;
    else
        vec = opaque_obj('Vec', arg);
    end
elseif nargin==1 || ~opaque
    vec = castdata('Vec', arg.data);
else % The argument is already an opaque object.
    vec = arg;
end
