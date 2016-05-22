function rmvFunc = PetscMatNullSpaceRemoveFunc(arg, opaque) %#codegen
%Map an opaque object into a MatNullSpaceRemoveFunc object
%
%  rmvFunc = PetscMatNullSpaceRemoveFunc() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument specification 
%  for codegen.
%
%  rmvFunc = PetscMatNullSpaceRemoveFunc(arg) or 
%  rmvFunc = PetscMatNullSpaceRemoveFunc(arg, false) 
%  converts arg into a MatNullSpaceRemoveFunc object.
%
%  rmvFunc = PetscMatNullSpaceRemoveFunc(arg, true) wraps the arg into an 
%  opaque object. This should be used if the object needs to be returned to 
%  MATLAB from the compiled C code.  Note that the value of opaque must be 
%  determined at compile time.
%
% See also petscMatNullSpaceSetFunction

coder.inline('always');

if nargin==0 && isempty(coder.target)
    rmvFunc = m2c_opaque_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'MatNullSpaceRemoveFunc')
    m2c_error('PetscMatNullSpaceRemoveFunc:WrongType', ...
        'Incorrect data type %s. Expected MatNullSpaceRemoveFunc.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        rmvFunc = arg;
    else
        rmvFunc = m2c_opaque_obj('MatNullSpaceRemoveFunc', arg);
    end
else
    rmvFunc = castdata('MatNullSpaceRemoveFunc', arg.data);
end
