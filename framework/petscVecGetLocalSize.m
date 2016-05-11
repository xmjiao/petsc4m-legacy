function [n, errCode] = petscVecGetLocalSize(vec)
%Returns the local number of elements of the vector.
%
%[n, errCode] = petscVecGetLocalSize(vec)
%  	vec   - the vector
%   n     - the number of elements
%
%  SEE ALSO: petscVecSetSizes, petscVecGetSize
%
% PETSc C interface:
%   PetscErrorCode VecGetLocalSize(Vec vec,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetLocalSize.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    
    n = int32(0);
    errCode = coder.ceval('VecGetLocalSize', t_vec, coder.wref(n));
    
    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecGetLocalSize returned error code %d\n', errCode)
    end
end
end
