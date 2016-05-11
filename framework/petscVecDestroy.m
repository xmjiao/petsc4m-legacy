function [vec, errCode, toplevel] = petscVecDestroy(vec)
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
    
    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode)
    end

    if nargout>2
        vec = opaque_obj('Vec', t_vec);
        toplevel = true;
    else
        vec = t_vec;
    end
end
end
