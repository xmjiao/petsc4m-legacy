% This script is called automatically when MATLAB and Octave exists.

if ~usejava('jvm')
    try 
        if exist(['petscInitialized.' mexext], 'file') && ...
                exist(['petscFinalized.' mexext], 'file')  && ...
                exist(['petscFinalize.' mexext], 'file')  && ...
                petscInitialized && ~petscFinalized
            petscFinalize;
        end
    catch
    end
end
