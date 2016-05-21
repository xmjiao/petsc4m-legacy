function load_mpetsc(arg)
%LOAD_MPETSC Load MPETSc into MATLAB/Octave for execution using mex files.

if exist('matlabroot', 'builtin') && (~ismac || usejava('jvm')) && ...
        (nargin==0 || ~isequal(arg, '-force'))
    warning('%s\n', ...
        'MPETSc in MATLAB on Linux or MATLAB with JVM on Mac is prone to crash.', ...
        'You can use still use mptSolveCRS through automatic file I/O and use ', ...
        'for code development and debugging, but the features under the mex', ...
        'subdirectory are not available. For production runs with MPETSc,', ...
        'use "matlab -nojvm" on Mac or use Octave on Linux.', ...
        'To force loading MPETSc in this MATLAB session, use load_mpetsc(''-force'').');
    return;
end

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
