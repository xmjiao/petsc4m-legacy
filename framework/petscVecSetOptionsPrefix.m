function errCode = petscVecSetOptionsPrefix(vec, in_str)
%Sets the prefix used for searching for all Vec options in the database.
%   errCode = petscVecSetOptionsPrefix(vec, in_str)
%
%   vec    - the Vec context
%   in_str - string that contains options separated by blanks
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: VecSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  VecSetOptionsPrefix(Vec v,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetOptionsPrefix.html

%#codegen -args {PetscVec, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = PetscVec(vec);
    % null-terminate the string.
    str0 = [in_str char(0)];
    
    errCode = coder.ceval('VecSetOptionsPrefix', t_vec, coder.rref(str0));

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
