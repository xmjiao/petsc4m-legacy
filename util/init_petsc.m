function init_petsc(arg)
%INIT_PETSC Load Petsc4m into MATLAB/Octave for execution using mex files.

if ~isoctave && usejava('jvm') && (nargin==0 || ~isequal(arg, '-force'))
    fprintf(1, '%s\n', ...
        'Note: The mex subdirectory was not added to the path, because PETSC is prone', ...
        'to crashing in MATLAB on Linux or in MATLAB with JVM on Mac. The top-level', ...
        'function petscSolveCRS will run through file I/O. The constants PETSC_* and', ...
        'the functions petscInitialied and petscFinalized are available in this MATLAB', ...
        'session. For production runs with Petsc4m, use "matlab -nojvm" on Mac or use', ...
        'Octave on Linux. To force loading the mex files, use init_petsc(''-force'').');
    return;
end

% Add mex files into path for faster execution
addpath([petscroot '/mex'])

if exist(['petscInitialize.' mexext], 'file') && ...
    isequal(which('petscInitialize'), which(['petscInitialize.' mexext]))
    try
        if ~petscInitialized
            init_mpi;
            petscInitialize;

            if isoctave
                atexit('uninit_petsc')
            end
        end
    catch
        warning('Failed to initialize petsc4m.')
        if isoctave
            warning('Try to set LD_LIBRARY_PATH=$PETSC_DIR/bin in shell and restart Octave');
        end
    end
else
    warning('Please run build_petsc and then init_petsc again')
end
