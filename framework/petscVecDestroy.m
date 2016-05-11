function [vec, errCode] = petscVecDestroy(vec)
%Frees space taken by a vector.
%
%  [vec, errCode] = petscVecDestroy(vec)
%
%  SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec,
%
% PETSc C interface:
%   PetscErrorCode VecDestroy(Vec *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecDestroy', coder.ref(t_vec));
    
    if errCode && (nargout==1 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode)
    end
    
    if isstruct(vec)
        % Create a MATLAB opaque object if the req is a MATLAB opaque object.
        vec = opaque_obj('Vec', t_vec);
    else
        vec = t_vec;
    end
end
end
