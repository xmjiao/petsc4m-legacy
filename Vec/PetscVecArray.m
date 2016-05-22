function output = PetscVecArray(arg, varargin) %#codegen
% Defines an array of PetscVec.
%
% vecs = PetscVecArray() returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
% vecs = PetscVecArray(n)
% Construst an array of PetscVec of size n-by-1.
%
% vecs = PetscVecArray(arg)
% Map an opaque object into PetscVecArray, where arg is an m2c_opaque_obj.
%
% vec = PetscVecArray(vecs, i, 'get')
% Obtain the ith entry in PetscVecArray as PetscVec, where i is one-based.
%
% vecs = PetscVecArray(vecs, i, 'set', vec)
% Set the ith-entry in PetscVecArray array to stat, where i is one-based,
% and vec is an opaque type.
%
% See also PetscVec, m2c_touch

coder.inline('always');

if nargin==0
    output = m2c_opaque_type;
    return;
end

if nargin==1 && isnumeric(arg) && ~isa(arg, 'uint8')
    m = int32(arg);
    n = petscGetSizeof('PetscVec');
    
    if isempty(coder.target)
        output = m2c_opaque_obj('PetscVec', zeros(m*n, 1, 'uint8'), m);
    else
        output = zeros(m*n, 1, 'uint8');
    end
elseif nargin==1
    if isstruct(arg) && ~isequal(arg.type, 'PetscVec')
        m2c_error('PetscVecArray:WrongType', ...
            'Incorrect data type %s. Expected PetscVec.', [arg.type char(0)]);
    end
    
    if ~isstruct(arg) || isempty(coder.target)
        output = arg;
    else
        output = castdata('Vec *', arg.data);
    end
elseif nargin==3
    if ~isequal(varargin{2}, 'get')
        error('When retrieving an entry, the third argument must be ''get''.\n');
    end
    assert(isnumeric(varargin{1}));
    n = petscGetSizeof('PetscVec');
    
    offset = n * (int32(varargin{1})-1);
    
    if isstruct(arg)
        output = m2c_opaque_obj('PetscVec', arg.data(offset+1:offset+n));
    else
        output = castdata('PetscVec', arg.data(offset+1:offset+n));
    end
elseif nargin==4
    if ~isequal(varargin{2}, 'set')
        error('When setting object, the third argument must be ''set''.\n');
    end
    assert(isnumeric(varargin{1}));
    
    n = petscGetSizeof('PetscVec');
    offset = (int32(varargin{1})-1) * n;
    
    i = varargin{1}; val = varargin{3};
    output = arg;
    % copy val into the ith entry
    if isstruct(arg)
        assert(isstruct(val));
        assert(i>=1 && i<=arg.nitems);
        
        output.data(offset+1:offset+n) = val.data;
    else
        vec = m2c_opaque_obj('PetscVec', val);
        output(offset+1:offset+n) = vec.data;
    end
else
    error('Incorrect input arguments.');
end
