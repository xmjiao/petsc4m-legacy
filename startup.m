% This script is called automatically when MATLAB and Octave exists.

addpath(pwd); %#ok<*MCAP>
addpath([pwd '/petsc']);
addpath([pwd '/util'])

if ~exist('MMPI_Init')
    addpath([pwd '/mpi'])
end

if ~exist('m2c', 'file') && exist('../M2C', 'dir')
    % Starting from the current directory with M2C. Load M2C and compile.
    run ../M2C/startup

    if usejava('jvm')
        run('util/build_mpetsc');
    end
end

% Initialize PETSc only when running without JVM
if ismac && ~usejava('jvm')
    try
        if exist(['petscInitialize.' mexext], 'file')
            petscInitialize;
        end
    catch
        warning('petscInitialize failed.');
    end
end
