function load_mpetsc(arg)
%LOAD_MPETSC Load MPETSc into MATLAB/Octave for execution using mex files.

if exist('matlabroot', 'builtin') && (~ismac || usejava('jvm')) && ...
        (nargin==0 || ~isequal(arg, '-force'))
    fprintf(1, '%s\n', ...
        'Loading PETSc into MATLAB through MEX files on Linux or with JVM', ...
        'enabled on Mac is prone to crashing. You can use mptSolveCRS through ', ...
        'file I/O, call petscInitialied, petscFinalized, and use all PETSC_* constants, ', ...
        'but the compiled features under the mex subdirectory are unavailable. For', ...
        'production runs with MPETSc, use "matlab -nojvm" on Mac or use Octave on Linux.', ...
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
