function vec = PetscVec(arg) %#codegen
%Map an opaque object into a PETSc Vec object
%
% vec = PetscVec(arg)
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    vec = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'Vec')
    m2c_error('PetscVec:WrongType', ...
        'Incorrect data type %s. Expected Vec.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    vec = arg;
else
    vec = castdata('Vec', arg.data);
end
