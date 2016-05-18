function [errCode, toplevel] = petscMatCopy(A, B, mstr)
%Copys a matrix to another matrix.
%
%  errCode = petscMatCopy(A, B) copies the entries from A to B, assuming
%     that they have the same nonzero patterns.
%
%  errCode = petscMatCopy(A, B, mstr) copies the entries from A to B. 
%     If mstr==PETSC_SAME_NONZERO_PATTERN, the matrices are assumed to have the
%     same nonzero patterns. Otherwise, mstr can be PETSC_DIFFERENT_NONZERO_PATTERN
%     or PETSC_SUBSET_NONZERO_PATTERN.
%
%  SEE ALSO: petscMatDuplicate, petscMatConvert
%
% PETSc C interface:
%   PetscErrorCode MatCopy(Mat A,Mat B,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatCopy.html

%#codegen -args {PetscMat, PetscMat, int32(0)}
%#codegen petscMatCopy_2args -args {PetscMat, PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    if nargin==2
        mstr = PETSC_SAME_NONZERO_PATTERN;
    end
    
    errCode = coder.ceval('MatCopy', PetscMat(A), PetscMat(B), mstr);
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatCopy returned error code %d\n', errCode)
    end
end
end
