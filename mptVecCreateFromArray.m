function [vec_out, toplevel] = mptVecCreateFromArray(arr, varargin)
%Creates a vector in PETSc from a MATLAB column vector.
%
%  vec = mptVecCreateFromArray(arr)
%     arr:   A column vector in MATLAB
%
%  vec = petscVecCreateFromArray(arr, prefix)
%     prefix: if present, set options of the vector from the options database.
%
%  The vector must be deallocated by calling petscVecDestroy after use.
%
%  SEE ALSO: petscVecDestroy, mptVecToArray, mptOptionsInsert

%#codegen -args {coder.typeof(0, [inf, 1])} mptVecCreateFromArray_2args -args
%#codegen {coder.typeof(0, [inf, 1]), coder.typeof(char(0), [1,inf])}

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
idx = (0:int32(n)-1)';
petscVecSetValues(vec, n, idx, arr);

% Call assembly
petscVecAssemblyBegin(vec);
petscVecAssemblyEnd(vec);

toplevel = nargout>1;
vec_out = PetscVec(vec, toplevel);

end

function test %#ok<DEFNU>
%!test
%! b = rand(10,1);
%! vec = mptVecCreateFromArray(b);
%! arr = mptVecToArray(vec);
%! assert(isequal(b, arr));
end

