function [vec_out, errCode, toplevel] = petscVecDuplicate(vec_in)
%Creates a new vector of the same type as an existing vector.
%
%  [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but
%     it does not copy the entries of the input vector. The user is
%     responsible freeing the memory by calling petscVecDestroy.
%
%  SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate
%
% PETSc C interface:
%   PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec_out = coder.opaque('Vec');

    errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out));

    toplevel = nargout>2;
    vec_out = PetscVec(t_vec_out, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! vec_y = petscVecDuplicate(vec_x);
%! errCode = petscVecCopy(vec_x, vec_y);
%!
%! y = petscVecToArray(vec_y);
%! petscVecDestroy(vec_x);
%! petscVecDestroy(vec_y);
%!
%! assert(errCode == 0 && isequal(y, x));
end
