function errCode = petscMatSetType(mat, type)
%Builds matrix object for a particular matrix type.
%
%   errCode = petscMatSetType(mat, type)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscMatCreate, petscMatSetValues
%
% PETSc C interface:
%   PetscErrorCode  MatSetType(Mat mat, MatType matype)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetType.html

%#codegen -args {PetscMat, PetscMatType}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    t_type = PetscMatType(type);
    
    errCode = coder.ceval('MatSetType', t_mat, t_type);
    
    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'MatSetType returned error code %d\n', errCode)
    end
end

end
