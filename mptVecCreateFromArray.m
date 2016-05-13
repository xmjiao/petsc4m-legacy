function [vec_out, toplevel] = mptVecCreateFromArray(arr, varargin)
%Creates a vector in PETSc from a MATLAB column vector.
%
%  vec = mptVecCreateFromArray(arr)
%     arr:   A column vector in MATLAB
%
%  vec = petscVecCreateFromArray(arr, prefix)
%     prefix: if present, set options of the vector from the options database.
%
%  SEE ALSO: mptVecToArray

%#codegen -args {coder.typeof(0, [inf, 1])} mptVecCreateFromArray_2args -args
%#codegen {coder.typeof(0, [inf, 1]), coder.typeof(char(0), [inf,1])}

if nargin<1
    error('At least one argument is required.');
end

n = int32(length(arr));

if nargin==1
    vec = petscVecCreateSeq(n);
else
    vec = petscVecCreate;
    petscVecSetOptionsPrefix(vec, varargin{1});
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

