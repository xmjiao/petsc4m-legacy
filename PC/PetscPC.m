function pc = PetscPC(arg, opaque) %#codegen
%Map an opaque object into a PETSc PC object
%
%  pc = PetscPC() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument
%  specification for codegen.
%
%  pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg
%  into a PETSc PC object.
%
%  pc = PetscPC(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscKSP

coder.inline('always');

if nargin==0 && isempty(coder.target)
    pc = m2c_opaque_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'PC')
    m2c_error('PetscPC:WrongType', ...
        'Incorrect data type %s. Expected PC.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        pc = arg;
    else
        pc = m2c_opaque_obj('PC', arg);
    end
else
    pc = castdata('PC', arg.data);
end
