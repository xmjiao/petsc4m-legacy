function mat = PetscMat(arg, opaque) %#codegen
%Map an opaque object into a PETSc Mat object
%
%  mat = PetscMat() simply returns a definition of the
%  m2c_opaque_type definition, suitable in the argument
%  specification for codegen.
%
%  mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg
%  into a PETSc Mat object.
%
%  mat = PetscMat(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    mat = m2c_opaque_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'Mat')
    m2c_error('PetscMat:WrongType', ...
        'Incorrect data type %s. Expected Mat.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        mat = arg;
    else
        mat = m2c_opaque_obj('Mat', arg);
    end
else
    mat = castdata('Mat', arg.data);
end
