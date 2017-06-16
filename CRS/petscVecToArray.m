function arr = petscVecToArray(vec)
%Export the local portion of a vector in PETSc to a MATLAB array.
%
%  arr = petscVecToArray(vec)
%     exports the PETSc vector vec into an array arr
%
%  SEE ALSO: petscVecCreateFromArray

if nargin<1
    error('At least one argument is required.');
end

n = petscVecGetLocalSize(vec);
arr = coder.nullcopy(zeros(n, 1));

% Obtain values
idx = int32(0:n-1)';
arr = petscVecGetValues(vec, n, idx, arr);

end

function test %#ok<DEFNU>
%!test
%! b = rand(10,1);
%! vec = petscVecCreateFromArray(b);
%! arr = petscVecToArray(vec);
%! assert(isequal(b, arr));
end
