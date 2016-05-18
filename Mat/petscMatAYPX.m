function [errCode, toplevel] = petscMatAYPX(Y, a, X, mstr)
%Computes Y = a*Y + X.
%
%  errCode = [errCode, toplevel] = petscMatAYPX(Y, a, X) computes
%     Y = a*Y + X, assuming X and Y have the same nonzero patterns.
%
%  errCode = [errCode, toplevel] = petscMatAYPX(Y, a, X, mstr) allows
%     specifying different nonzero patterns form X and Y. If mstr==
%     PETSC_SAME_NONZERO_PATTERN, the matrices are assumed to have the
%     same nonzero patterns. Otherwise, mstr can be PETSC_DIFFERENT_NONZERO_PATTERN
%     or PETSC_SUBSET_NONZERO_PATTERN.
%
%  SEE ALSO: petscMatAYPX
%
% PETSc C interface:
%   PetscErrorCode MatAYPX(Mat Y,PetscScalar a,Mat X,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAYPX.html

%#codegen -args {PetscMat, 0, PetscMat, int32(0)}
%#codegen petscMatAYPX_3args -args {PetscMat, 0, PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    if nargin==3
        mstr = PETSC_SAME_NONZERO_PATTERN;
    end
    
    errCode = coder.ceval('MatAYPX', PetscMat(Y), a, PetscMat(X), mstr);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatAYPX returned error code %d\n', errCode)
    end
end
end
