function errCode = petscMatAssemblyBegin(mat,type)
%Begins assembling the matrix. This routine should be called after 
%completing all calls to petscMatSetValues().
%
%  errCode = petscMatAssemblyBegin(mat, [type=petscMAT_FINAL_ASSEMBLY])
%
%  SEE ALSO: petscAssembleMat, petscMatAssemblyEnd, petscMatSetValues
%
% PETSc C interface:
%   PetscErrorCode MatAssemblyBegin(Mat mat,MatAssemblyType type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAssemblyBegin.html

%#codegen -args {PetscMat,int32(0)} petscMatAssemblyBegin_Final -args {PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    if nargin<2; type = PETSC_MAT_FINAL_ASSEMBLY; end
    
    errCode = coder.ceval('MatAssemblyBegin',t_mat,type);

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'MatAssemblyBegin returned error code %d\n', errCode)
    end
end
end
