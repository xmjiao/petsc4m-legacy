function vec = petscVecCreateFromArray(arr, varargin)
%Creates a vector in PETSc from a MATLAB column vector.
%
%  vec = petscVecCreateFromArray(arr)
%     arr:   A column vector in MATLAB
%
%  vec = petscVecCreateFromArray(arr, prefix)
%     prefix: if present, set options of the vector from the options database.
%
%  The vector must be deallocated by calling petscVecDestroy after use.
%
%  SEE ALSO: petscVecDestroy, petscVecToArray, petscOptionsInsert

if nargin<1
    error('At least one argument is required.');
end

n = int32(length(arr));

if nargin==1
    vec = petscVecCreateSeq(n);
else
    vec = petscVecCreate;
    if isempty(varargin{1}) || ~varargin{1}(end)
        prefix = varargin{1};
    else
        % Null-terminate the string
        prefix = [varargin{1} char(0)];
    end

    petscVecSetOptionsPrefix(vec, prefix);
    petscVecSetFromOptions(vec);
    petscVecSetSizes(vec, n);
end

% Set values
idx = int32(0:n-1)';
petscVecSetValues(vec, n, idx, arr);

% Call assembly
petscVecAssemblyBegin(vec);
petscVecAssemblyEnd(vec);

end

function test %#ok<DEFNU>
%!test
%! b = rand(10,1);
%! vec = petscVecCreateFromArray(b);
%! arr = petscVecToArray(vec);
%! assert(isequal(b, arr));
end
