function [n, errCode] = petscVecGetSize(vec)
%Returns the global number of elements of the vector.
%
%[n, errCode] = petscVecGetSize(vec)
%  	vec   - the vector
%   n     - the number of elements
%
%  SEE ALSO: petscVecSetSizes, petscVecGetLocalSize
%
% PETSc C interface:
%   PetscErrorCode VecGetSize(Vec vec,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetSize.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    
    n = int32(0);
    errCode = coder.ceval('VecGetSize', t_vec, coder.wref(n));
    
    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecGetSize returned error code %d\n', errCode)
    end
end
end
