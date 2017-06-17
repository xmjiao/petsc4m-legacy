function [val, errCode, toplevel] = petscVecDot(x, y)
%Computes the vector dot product.
%
%  [val, errCode] = petscVecDot(y, a, x) computes
%     y = a*x + y.
%
%  SEE ALSO: petscVecAYPX
%
% PETSc C interface:
%   PetscErrorCode  VecDot(Vec x,Vec y,PetscScalar *val)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDot.html

%#codegen -args {PetscVec, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    val = double(0);
    errCode = coder.ceval('VecDot', PetscVec(x), PetscVec(y), coder.wref(val));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecDot returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! y = rand(10,1);
%! x = rand(10,1);
%!
%! vec_y = petscVecCreateFromArray(y);
%! vec_x = petscVecCreateFromArray(x);
%!
%! [result, errCode] = petscVecDot(vec_x, vec_y);
%!
%! petscVecDestroy(vec_x);
%! petscVecDestroy(vec_y);
%!
%! assert(errCode == 0 && norm(result - x' * y) < 1.e-12);
end
