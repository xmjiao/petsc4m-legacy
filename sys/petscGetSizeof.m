function [sz, toplevel] = petscGetSizeof(name)
%petscGetEnum Obtain the size of a PETSc object in bytes.
%
%    sze = petscGetSizeof(name)
%
%The supported names include:
%
% PetscMat, PetscVec, PetscObject

%#codegen -args {coder.typeof(char(0),[1,inf])}

coder.cinclude('mpetsc.h');

if isempty(coder.target)
    error('Function petscGetEnum must be compiled.');
end

switch name
    case 'PetscVec'
        [sz, toplevel] = get_size('Vec', nargin>1);
    case 'PetscMat'
        [sz, toplevel] = get_size('Mat', nargin>1);
    case 'PetscObject'
        [sz, toplevel] = get_size('PetscObject', nargin>1);
    otherwise
        toplevel = nargout>1;
        sz = int32(intmin);
        if toplevel
            m2c_error('petscGetSizeof:UnknownType', 'Unknonw data type %s.', [name char(0)]);
        end
end
end

function [sz, toplevel] = get_size(type, toplevel)
coder.inline('always');

sz = int32(intmin);             %#ok<NASGU>
sz = coder.ceval('sizeof', coder.opaque('ctype', type));
end
