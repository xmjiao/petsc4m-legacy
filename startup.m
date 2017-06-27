% This script is called automatically when MATLAB and Octave exists.
if exist('OCTAVE_VERSION', 'builtin')
    more off;
else
    warning('off', 'MATLAB:mex:GccVersion_link');
end
load_petsc;
