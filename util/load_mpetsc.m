function load_mpetsc
%LOAD_MPETSC Load MPETSc into MATLAB for execution using mex files.

try
    % Add mex files into path for faster execution
    addpath([pwd '/mex'])
    
    if exist(['mpi_Init' mexext], 'file') && ...
            exist(['mpi_Initialized' mexext], 'file') && ...
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
