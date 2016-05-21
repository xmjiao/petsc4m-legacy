function [errCode, toplevel] = petscMatAXPY(Y, a, X, mstr)
%Computes Y = a*X + Y.
%
%  errCode = [errCode, toplevel] = petscMatAXPY(Y, a, X) computes
%     Y = a*X + Y, assuming X and Y have the same nonzero patterns.
%
%  errCode = [errCode, toplevel] = petscMatAXPY(Y, a, X, mstr) allows
%     specifying different nonzero patterns form X and Y. If mstr==
%     PETSC_SAME_NONZERO_PATTERN, the matrices are assumed to have the
%     same nonzero patterns. Otherwise, mstr can be PETSC_DIFFERENT_NONZERO_PATTERN
%     or PETSC_SUBSET_NONZERO_PATTERN.
%
%  SEE ALSO: petscMatAYPX
%
% PETSc C interface:
%   PetscErrorCode MatAXPY(Mat Y,PetscScalar a,Mat X,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAXPY.html

%#codegen -args {PetscMat, 0, PetscMat, int32(0)}
%#codegen petscMatAXPY_3args -args {PetscMat, 0, PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    if nargin==3
        mstr = PETSC_SAME_NONZERO_PATTERN;
    end
    
    errCode = coder.ceval('MatAXPY', PetscMat(Y), a, PetscMat(X), mstr);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatAXPY returned error code %d\n', errCode)
    end
end
end
