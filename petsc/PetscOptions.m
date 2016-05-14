function opts = PetscOptions(arg, opaque) %#codegen
%Map an opaque object into a PETSc PetscOptions object
%
%  opts = PetscOptions() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  opts = PetscOptions(arg) or opts = PetscOptions(arg, false) converts arg
%  into a PETSc Options object.
%
%  opts = PetscOptions(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    opts = opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'PetscOptions')
    m2c_error('PetscOptions:WrongType', ...
        'Incorrect data type %s. Expected PetscOptions.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        opts = arg;
    else
        opts = opaque_obj('PetscOptions', arg);
    end
else
    opts = castdata('PetscOptions', arg.data);
end
