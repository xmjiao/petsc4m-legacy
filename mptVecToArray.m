function arr = mptVecToArray(vec)
%Export the local portion of a vector in PETSc to a MATLAB array.
%
%  arr = mptVecToArray(vec)
%     exports the PETSc vector vec into an array arr
%
%  SEE ALSO: mptVecCreateFromArray

if nargin<1
    error('At least one argument is required.');
end

n = petscVecGetLocalSize(vec);
arr = coder.nullcopy(zeros(n, 1));

% Obtain values
idx = (0:int32(n)-1)';
arr = petscVecGetValues(vec, n, idx, arr);

end

function test %#ok<DEFNU>
%!test
%! b = rand(10,1);
%! vec = mptVecCreateFromArray(b);
%! arr = mptVecToArray(vec);
%! assert(isequal(b, arr));
end
