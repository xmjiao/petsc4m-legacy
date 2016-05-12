function arr = petscVecToArray(vec, arr)
%Export the local portion of a vector in PETSc to a MATLAB array.
%
%  arr = petscVecToArray(vec)
%     exports the PETSc vector vec into an array arr
%
%  arr = petscVecToArray(vec, arr)
%     exports the vector into the space preallocated in arr
%
%  SEE ALSO: petscVecCreateFromArray

%#codegen

if nargin<1
    error('At least one argument is required.');
end

n = petscVecGetLocalSize(vec);

if nargin==1
    arr = coder.nullcopy(zeros(n, 1));
elseif length(arr)~=n
    error('Input arr does not have correct size.');
end

% Obtain values
idx = (0:int32(n)-1)';
arr = petscVecGetValues(vec, n, idx, arr);

end

function test %#ok<DEFNU>
%!test
%! b = rand(10,1);
%! vec = petscVecCreateFromArray(b);
%! arr = petscVecToArray(vec);
%! assert(isequal(b, arr));
end
