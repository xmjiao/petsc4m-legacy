function init_petsc(arg)
%INIT_PETSC Load Petsc4m into MATLAB/Octave for execution using mex files.

if ~isoctave && (~ismac || usejava('jvm')) && ...
        (nargin==0 || ~isequal(arg, '-force'))
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
init_mpi;

if exist(['petscInitialize.' mexext], 'file')
    try
        petscInitialize;
    catch
        warning('petscInitialize failed.');
    end

    if isoctave
        atexit('uninit_petsc')
    end
else
    warning('Petsc4m has not been built. Run build_petsc and then init_petsc again.')
end

end
