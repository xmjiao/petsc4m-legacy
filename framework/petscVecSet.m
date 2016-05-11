function errCode = petscVecSet(vec, val)
%Sets all components of a vector to a single scalar value.
%
%  errCode = petscVecSet(vec, val)
%
%  SEE ALSO: petscAssembleVec, petscDestroyVec
%
% PETSc C interface:
%   PetscErrorCode  VecSet(Vec x,PetscScalar alpha)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSet.html

%#codegen -args {PetscVec, 0}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecSet', t_vec, val);

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecSet returned error code %d\n', errCode)
    end
end
end
