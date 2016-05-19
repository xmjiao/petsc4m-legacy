function load_mpetsc
%LOAD_MPETSC Load MPETSc into MATLAB for execution using mex files.

mpetscroot = fileparts(which('startup_mpetsc'));

try
    % Add mex files into path for faster execution
    addpath([mpetscroot '/mex'])
    
    if exist(['mpi_Init' mexext], 'file') && ...
            exist(['mpi_Initialized' mexext], 'file') && ...
            exist(['mpi_Barrier' mexext], 'file') && ...
            ~mpi_Initialized
        mpi_Init;
    end
    
    if exist(['petscInitialize.' mexext], 'file')
        petscInitialize;
    end
catch
    warning('petscInitialize failed.');
end

end
