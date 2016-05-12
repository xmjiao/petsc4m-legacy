function ksp = PetscKSP(arg) %#codegen
%Map an opaque object into a PETSc KSP object
%
% ksp = PetscKSP(arg)
%
% See also PescVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    ksp = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'KSP')
    m2c_error('PetscKSP:WrongType', ...
        'Incorrect data type %s. Expected KSP.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    ksp = arg;
else
    ksp = castdata('KSP', arg.data);
end
