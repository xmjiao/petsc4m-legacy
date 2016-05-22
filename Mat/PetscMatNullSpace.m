function matNull = PetscMatNullSpace(arg, opaque) %#codegen
%Map an opaque object into a PETSc MatNullSpace object
%
%  matNull = PetscMatNullSpace() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument specification 
%  for codegen.
%
%  matNull = PetscMatNullSpace(arg) or matNull = PetscMatNullSpace(arg, false) 
%  converts arg into a PETSc MatNullSpace object.
%
%  matNull = PetscMatNullSpace(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to MATLAB from 
%  the compiled C code.  Note that the value of opaque must be determined at
%  compile time.
%
% See also petscMatNullSpaceCreate

coder.inline('always');

if nargin==0 && isempty(coder.target)
    matNull = m2c_opaque_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'MatNullSpace')
    m2c_error('PetscMatNullSpace:WrongType', ...
        'Incorrect data type %s. Expected MatNullSpace.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        matNull = arg;
    else
        matNull = m2c_opaque_obj('MatNullSpace', arg);
    end
else
    matNull = castdata('MatNullSpace', arg.data);
end
