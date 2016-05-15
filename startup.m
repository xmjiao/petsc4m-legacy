% This script is called automatically when MATLAB and Octave exists.

addpath(pwd); %#ok<*MCAP>
addpath([pwd '/petsc']);
addpath([pwd '/util'])
addpath([pwd '/sys'])

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
        if exist(['mpi_Init' mexext], 'file') && ...
                exist(['mpi_Initialized' mexext], 'file') && ...
                ~mpi_Initialized
%            mpi_Init;
        end
        if exist(['petscInitialize.' mexext], 'file')
            petscInitialize;
        end
    catch
        warning('petscInitialize failed.');
    end
end
