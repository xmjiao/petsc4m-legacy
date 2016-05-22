function load_mpetsc(arg)
%LOAD_MPETSC Load MPETSc into MATLAB/Octave for execution using mex files.

mpetscroot = fileparts(which('startup_mpetsc'));

if exist('matlabroot', 'builtin') && (~ismac || usejava('jvm')) && ...
        (nargin==0 || ~isequal(arg, '-force'))
    fprintf(1, '%s\n', ...
        'Note: The mex subdirectory was not added to the path, because PETSC is prone', ...
        'to crashing in MATLAB on Linux or in MATLAB with JVM on Mac. The top-level', ...
        'function mptSolveCRS will run through file I/O. The constants PETSC_* and', ...
        'the functions petscInitialied and petscFinalized are available in this MATLAB', ...
        'session. For production runs with MPETSc, use "matlab -nojvm" on Mac or use', ...
        'Octave on Linux. To force loading the mex files, use load_mpetsc(''-force'').');

    return;
end


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
