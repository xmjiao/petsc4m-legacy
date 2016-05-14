% This script is called automatically when MATLAB and Octave exists.

if ~usejava('jvm')
    try 
        if exist(['petscInitialized.' mexext], 'file') && ...
                exist(['petscFinalized.' mexext], 'file')  && ...
                exist(['petscFinalize.' mexext], 'file')  && ...
                petscInitialized && ~petscFinalized
            petscFinalize;
        end

        if exist(['mpi_Finialize' mexext], 'file') && ...
                exist(['mpi_Initialized' mexext], 'file') && ...
                exist(['mpi_Finialize' mexext], 'file') && ...
                mpi_Initialized && ~mpi_Finialized
            mpi_Finialize;
        end
    catch
    end
end
