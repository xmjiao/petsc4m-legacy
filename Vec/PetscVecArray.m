function output = PetscVecArray(varargin) %#codegen
% Defines an array of PetscVec.
%
% PetscVecArray() returns a definition of m2c_opaque_type,
% suitable in the type specifications for codegen.
%
% array = PetscVecArray(n)
% Construct an n-by-1 array of objects of the given base data.
%
% PetscVecArray(obj, n) or PetscVecArray(obj, n, false)
% maps a PetscVec object into a corresponding C type based on context.
%
% PetscVecArray(obj, n, 'wrap') or PetscVecArray(obj, n, true)
% wraps n PetscVec objects into an array.
%
% array = PetscVecArray(array, 'set', i, val)
% Set the ith-entry in PetscVecArray to the given value, where i is a
% one-based index, and vec is an opaque type.
%
% val = PetscVecArray(array, 'get', i)
% Obtain the ith entry in PetscVecArray, where i is one-based.
%
% See also PetscVec, m2c_opaque_array

coder.inline('always');

if nargin==1 && isnumeric(varargin{1})
    output = m2c_opaque_array('Vec', varargin{1}, petscGetSizeof('PetscVec'));
else
    output = m2c_opaque_array('Vec', varargin{:});
end
