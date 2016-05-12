function ksp = PetscPC(arg) %#codegen
%Map an opaque object into a PETSc PC object
%
% ksp = PetscPC(arg)
%
% See also PescVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    ksp = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'PC')
    m2c_error('PetscPC:WrongType', ...
        'Incorrect data type %s. Expected PC.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    ksp = arg;
else
    ksp = castdata('PC', arg.data);
end
