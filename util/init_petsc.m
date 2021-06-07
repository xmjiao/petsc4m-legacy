function init_petsc
%INIT_PETSC Load Petsc4m into MATLAB/Octave for execution using mex files.

if exist(['petscInitialize.' mexext], 'file') && ...
    isequal(which('petscInitialize'), which(['petscInitialize.' mexext]))
    try
        if ~petscInitialized
            %init_mpi;
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
