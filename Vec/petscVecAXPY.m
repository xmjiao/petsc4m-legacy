function [errCode, toplevel] = petscVecAXPY(y, a, x)
%Computes y = a*x + y.
%
%  errCode = petscVecAXPY(y, a, x) computes
%     y = a*x + y, where x and y MUST be different vectors
%
%  SEE ALSO: petscVecAYPX
%
% PETSc C interface:
%   PetscErrorCode VecAXPY(Vec y,PetscScalar a,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAXPY.html

%#codegen -args {PetscVec, 0, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('VecAXPY', PetscVec(y), a, PetscVec(x));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecAXPY returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! y = rand(10,1);
%! a = 2;
%! x = rand(10,1);
%!
%! vec_y = petscVecCreateFromArray(y);
%! vec_x = petscVecCreateFromArray(x);
%!
%! errCode = petscVecAXPY(vec_y, a, vec_x);
%!
%! result = petscVecToArray(vec_y);
%!
%! assert(errCode == 0 && norm(result - (y + a * x)) <= 1.e-12);
end
