function [assembled, errCode, toplevel] = petscMatAssembled(mat)
%Indicates if a matrix has been assembled and is ready for use.
%
%   [assembled, errCode] = MatAssemblyEnd(mat)
%
%   assembled(int)
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscMatAssemblyEnd, petscMatSetValues, petscMatAssemblyBegin
%
% PETSc C interface:
%   PetscErrorCode MatAssembled(Mat mat,PetscBool  *assembled)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAssembled.html#MatAssembled

%#codegen -args {PetscMat}

assembled = int32(0);
errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    b = coder.opaque('PetscBool');
    errCode = coder.ceval('MatAssembled', t_mat, coder.wref(b));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatAssembled returned error code %d\n', errCode)
    end
    assembled = coder.ceval(' ', b);
end

end
