function [errCode, toplevel] = petscOptionsInsertFile(comm, file, req)
%Inserts options into the database from a file.
%   errCode = petscOptionsInsertFile(comm, file, req)
%
% SEE ALSO: petscOptionsInsertString
%
% PETSc C interface:
%   PetscErrorCode  PetscOptionsInsertFile(MPI_Comm comm,PetscOptions options,const char file[],PetscBool require)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsInsertFile.html

%#codegen -args {MPI_Comm, coder.typeof(char(0), [1, inf]), int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    toplevel = nargout>1;
    if ~isempty(file) && file(end) && (toplevel || m2c_debug)
        m2c_error('Petsc4m:petscOptionsInsertFile:InputError', ...
            'Argument file must be a null-terminated string.')
    end
    
    errCode = coder.ceval('PetscOptionsInsertFile', MPI_Comm(comm), ...
        PETSC_NULL_OPTIONS, coder.rref(file), req);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscOptionsInsertFile returned error code %d\n', errCode)
    end
end

end
