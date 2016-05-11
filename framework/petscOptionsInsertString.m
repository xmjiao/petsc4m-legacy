function errCode = petscOptionsInsertString(in_str)
%Inserts options into the database from a string
%   errCode = petscOptionsInsertString(in_str)
%
%   in_str -string that contains options separated by blanks 
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscAssembleMat, petscAssembleVec, petscSolve
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsInsertString(PetscOptions options,const char in_str[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsInsertString.html

%#codegen -args {coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    % null-terminate the string.
    str0 = [in_str char(0)];

    options = coder.opaque('PetscOptions', 'NULL');
    errCode = coder.ceval('PetscOptionsInsertString', options, coder.rref(str0));

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'PetscOptionsInsertString returned error code %d\n', errCode)
    end
end

end
