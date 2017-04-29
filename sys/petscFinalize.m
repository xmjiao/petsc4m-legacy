function [errCode, toplevel] = petscFinalize
% Finalize PETSc by calling PetscFinalize()
%   errCode = petscFinalize
%
%   errCode(int) return code (0 indicates OK)
%
%This function should not be called explicitly by the user. It is called
%automatically when the MATLAB session terminates if petscInitialized is 
%true. 
%
%In a parallel setting, mpi_Finalize should be called explicitly after
%petscFinalize if mpi_Init was called explicitly before petscInitialize.
%
% PETSc C interface:
%   PetscErrorCode  PetscFinalize(void)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscFinalize.html

%#codegen -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('petsc4m.h');
    errCode = coder.ceval('PetscFinalize');

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscFinalize returned error code %d\n', errCode)
    end
end

end
