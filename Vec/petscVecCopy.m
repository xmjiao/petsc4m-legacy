function [errCode, toplevel] = petscVecCopy(x, y)
%Creates a vector from x to y.
%
%  errCode = petscVecCopy(x, y) copies the entries from x to y. Both
%  x and y must be distributed in the same manner; local copies are done.
%
%  SEE ALSO: petscVecDuplicate
%
% PETSc C interface:
%   PetscErrorCode  VecCopy(Vec x, Vec y)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCopy.html

%#codegen -args {PetscVec, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('VecCopy', PetscVec(x), PetscVec(y));

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecCopy returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! vec_y = petscVecCreateSeq(int32(10));
%!
%! errCode = petscVecCopy(vec_x, vec_y);
%!
%! y = petscVecToArray(vec_y);
%! petscVecDestroy(vec_x);
%! petscVecDestroy(vec_y);
%!
%! assert(errCode == 0 && isequal(y, x));
end
