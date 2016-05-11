function [mat, errCode, toplevel] = petscMatDestroy(mat)
%Frees space taken by a matrix.
%
%  [mat, errCode] = petscMatDestroy(mat)
%
%  SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy
%
% PETSc C interface:
%   PetscErrorCode MatDestroy(Mat *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    errCode = coder.ceval('MatDestroy', coder.ref(t_mat));
    
    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode)
    end
    
    if nargout>2
        % Create a MATLAB opaque object if the req is a MATLAB opaque object.
        mat = opaque_obj('Mat', t_mat);
        toplevel = true;
    else
        mat = t_mat;
    end
end
end
