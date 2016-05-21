function [errCode, toplevel] = petscVecAssemblyEnd(vec)
%Frees space taken by a vector.
%
%  errCode = petscVecAssemblyEnd(vec)
%
%  SEE ALSO: petscAssembleVec, petscVecAssemblyBegin, petscVecSetValues
%
% PETSc C interface:
%   PetscErrorCode VecAssemblyEnd(Vec *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAssemblyEnd.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecAssemblyEnd', t_vec);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecAssemblyEnd returned error code %d\n', errCode)
    end
end
end
