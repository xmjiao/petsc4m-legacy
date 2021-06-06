function [errCode, toplevel] = petscInitialize
%Initialize PETSc by calling PetscInitializeNoPointers()
%   errCode = petscInitialize
%
%   errCode(int) return code (0 indicates OK)
%
%This function should not be called explicitly by the user. It is called
%automatically when the PETSc module is loaded into MATLAB. This function
%also calls MPI_Init automatically if MPI was not initialized.
%
%In a parallel setting, MPI_Init must be called before petscInitialize
%by passing the command-line options to it. This is done automatically
%by loading M2C before loading PETSc.
%
% SEE ALSO: petscInitialized, petscFinalize, PetscFinalized
%
% PETSc C interface:
%   PetscErrorCode  PetscInitializeNoPointers(int argc,char **args,const char *filename,const char *help)
% This is an undocumented function in PETSc. It turns off PETSc signal handling because
% that can interact with MATLAB's signal handling causing random crashes.

%#codegen -args {}

errCode = int32(0);
coder.cinclude('petsc4m.h');

if ~isempty(coder.target)

    errCode = coder.ceval('PetscInitializeNoPointers', int32(0), PETSC_NULL, PETSC_NULL, PETSC_NULL);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscInitializeNoPointers returned error code %d\n', errCode)
    end
else
    error('To use Petsc4m low-level functions, you must compile Petsc4m. Try to run build_petsc and then init_petsc.');
end
end
