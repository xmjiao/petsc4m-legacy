function [errCode, toplevel] = petscVecSetSizes(vec, n, N)
%Sets the local and global sizes, and checks to determine compatibility.
%
%errCode = petscVecSetSizes(vec, n)
%  	vec   - the vector
%   n     - the local size
%   In this case, the global size is PETSC_DECIDE
%
% errCode = petscVecSetSizes(vec, n, N)
%   N	  - the global size
%
%  SEE ALSO: petscVecGetSize, petscSplitOwnership
%
% PETSc C interface:
%   PetscErrorCode  VecSetSizes(Vec v, PetscInt n, PetscInt N)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetSizes.html

%#codegen -args {PetscVec, int32(0), int32(0)}
%#codegen petscVecSetSizes_Local -args {PetscVec, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);
    
    if nargin<3
        N = PETSC_DECIDE;
    end
    errCode = coder.ceval('VecSetSizes', t_vec, n, N);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetSizes returned error code %d\n', errCode)
    end
end
end
