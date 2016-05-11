% This script is called automatically when MATLAB and Octave exists.

if petscInitialized && ~petscFinalized
    petscFinalize;
end
