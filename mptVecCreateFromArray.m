function vec = petscVecCreateFromArray(arr, options, prefix)
%Creates a vector in PETSc from a MATLAB array.
%
%  vec = petscVecCreateFromArray(arr)
%     arr:   A column vector in MATLAB
%
%  vec = petscVecCreateFromArray(arr, options, prefix)
%     options:   a character string containing options for the vector
%     prefix:    a character string specifics the prefix for the options
%
%  SEE ALSO: petscMatCreateFromCRS, petscVecToArray

%#codegen

if nargin<1
    error('At least one argument is required.');
end

n = int32(length(arr));

if nargin==1
    vec = petscVecCreateSeq(n);
else
    vec = petscVecCreate;
    if nargin>=5
        petscVecSetOptionsPrefix(vec, prefix);
    end
    petscOptionsInsertString(options)
    petscVecSetFromOptions(vec);
    petscVecSetSizes(vec, n);
end

% Set values
idx = (0:int32(n)-1)';
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

