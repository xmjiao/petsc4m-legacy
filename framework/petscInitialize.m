function [errCode, toplevel] = petscInitialize
%Initialize PETSc by calling PetscInitializeNoArguments()
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
%by loading MMPI before loading PETSc.
%
% SEE ALSO: petscInitialized, petscFinalize, PetscFinalized
%
% PETSc C interface:
%   PetscErrorCode  PetscInitializeNoArguments(void)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscInitializeNoArguments.html

%#codegen -args {}

errCode = int32(0);

if ~coder.target('MATLAB')
    errCode = coder.ceval('PetscInitializeNoArguments');

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscInitializeNoArguments returned error code %d\n', errCode)
    end
end
end
