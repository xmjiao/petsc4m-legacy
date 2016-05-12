% This script is called automatically when MATLAB and Octave exists.

if ~usejava('jvm') && petscInitialized && ~petscFinalized
    petscFinalize;
end
