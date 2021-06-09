function init_petsc(varargin)
%INIT_PETSC Load Petsc4m into MATLAB/Octave for execution using mex files.

if exist(['petscInitialize.' mexext], 'file') && ...
    isequal(which('petscInitialize'), which(['petscInitialize.' mexext]))
    try
        if ~petscInitialized
            if ~isoctave && usejava('jvm')
                warning('Petsc4m:JavaConflict', ...
                    ['Petsc4m is prone to crashing in MATLAB desktop environment ', ...
                    newline, 'due to apparent conflict with JAVA. Consider starting MATLAB', ...
                    newline, 'in command-line mode without JAVA with command `matlab -nojvm`', ...
                    newline, 'when using Petsc4m.']);
            end
            %init_mpi;
            petscInitialize;

            if isoctave
                atexit('uninit_petsc')
            end
        end
    catch
        warning('Petsc4m:FailedInit', 'Failed to initialize petsc4m.')
        if isoctave
            warning('Try to set LD_LIBRARY_PATH=$PETSC_DIR/bin in shell and restart Octave');
        end
    end
else
    warning('Petsc4m:NeedBuild', 'Please run build_petsc and then init_petsc again')
end
