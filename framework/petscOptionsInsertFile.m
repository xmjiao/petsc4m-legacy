function [errCode, toplevel] = petscOptionsInsertFile(comm, opts, file, req)
%Inserts options into the database from a file.
%   errCode = petscOptionsInsertFile(comm, opts, file, req)
%
% SEE ALSO: petscOptionsInsertString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsInsertFile(MPI_Comm comm,PetscOptions options,const char file[],PetscBool require)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsInsertFile.html

%#codegen -args {MPI_Comm, PetscOptions, coder.typeof(char(0), [1, inf]), int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    % null-terminate the string.
    
    errCode = coder.ceval('PetscOptionsInsertFile', MPI_Comm(comm), ...
        PetscOptions(opts), file, req);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsInsertFile returned error code %d\n', errCode)
    end
end

end
