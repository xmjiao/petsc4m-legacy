function [errCode, toplevel] = petscMatAssemblyEnd(mat, type)
%Completes assembling the matrix. This routine should be called after 
%petscMatAssemblyBegin().
%
%  errCode = petscMatAssemblyEnd(mat, [type=petscMAT_FINAL_ASSEMBLY])
%
%  SEE ALSO: petscAssembleMat, petscMatAssemblyBegin, petscMatSetValues
%
% PETSc C interface:
%   PetscErrorCode MatAssemblyEnd(Mat mat,MatAssemblyType type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAssemblyEnd.html

%#codegen -args {PetscMat,int32(0)} petscMatAssemblyEnd_Final -args {PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    if nargin<2; type = PETSC_MAT_FINAL_ASSEMBLY; end

    errCode = coder.ceval('MatAssemblyEnd', t_mat, type);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatAssemblyEnd returned error code %d\n', errCode)
    end
end
end
