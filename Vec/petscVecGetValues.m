function [y, errCode, toplevel] = petscVecGetValues(vec, ni, ix, y)
%Gets values from certain locations of a vector.
%Currently can only get values on the same processor
%
%  [y, errCode] = petscVecGetValues(vec, ni, ix)
%  	  vec - vector to get values from
%     ni  - number of elements to get
%     ix  - indices where to get them from (0-based in global 1d numbering)
%
%  [y, errCode] = petscVecGetValues(vec, ni, ix, y)
%     Use preallocated storage in y
%
%  SEE ALSO: petscVecAssemblyBegin, petscVecAssemblyEnd, petscVecSetValues
%
% PETSc C interface:
%   PetscErrorCode  VecGetValues(Vec x,PetscInt ni,const PetscInt ix[],PetscScalar y[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetValues.html

%#codegen -args {PetscVec, int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}
%#codegen petscVecGetValues_Alloc -args {PetscVec, int32(0), coder.typeof(int32(0), [inf,1])}

errCode = int32(-1);

if ~isempty(coder.target)
    if nargin<4
        y = coder.nullcopy(zeros(ni, 1));
    elseif length(y) < ni
        m2c_error('Output array y is too small.');
    end

    t_vec = PetscVec(vec);
    errCode = coder.ceval('VecGetValues', t_vec, ni, coder.rref(ix), coder.ref(y));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecGetValues returned error code %d\n', errCode)
    end
end
end


function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! y = zeros(5, 1);
%! idx = int32(5:9)';
%!
%! [y, errCode, toplevel] = petscVecGetValues(vec_x, int32(5),idx, y);
%! petscVecDestroy(vec_x);
%!
%! assert(errCode == 0 && isequal(y, x(idx+1)));
end
