function [errCode, toplevel] = petscVecAssemblyBegin(vec)
%Frees space taken by a vector.
%
%  errCode = petscVecAssemblyBegin(vec)
%
%  SEE ALSO: petscAssembleVec, petscVecAssemblyEnd, petscVecSetValues
%
% PETSc C interface:
%   PetscErrorCode VecAssemblyBegin(Vec *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAssemblyBegin.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecAssemblyBegin', t_vec);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecAssemblyBegin returned error code %d\n', errCode)
    end
end
end
