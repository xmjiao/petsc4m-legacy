function obj = PetscObject(arg) %#codegen
%Map an opaque object into a PetscObject object
%
% obj = PetscObject(arg)
%
% See also PescVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    obj = opaque_obj; return;
end

if isstruct(arg) && (~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ~isequal(arg.type, 'KSP'))
    m2c_error('PetscObject:WrongType', ...
        'Incorrect data type %s. Expected Mat, Vec, or KSP.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    obj = arg;
else
    obj = castdata('PetscObject', arg.data);
end
