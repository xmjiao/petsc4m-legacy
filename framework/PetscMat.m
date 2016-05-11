function mat = PetscMat(arg) %#codegen
%Map an opaque object into a PETSc Mat object
%
% mat = PetscMat(arg)
%
% See also PescVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    mat = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'Mat')
    m2c_error('PetscMat:WrongType', ...
        'Incorrect data type %s. Expected Mat.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    mat = arg;
else
    mat = castdata('Mat', arg.data);
end
