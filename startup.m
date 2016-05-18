% This script is called automatically when MATLAB and Octave exists.

addpath(pwd); %#ok<*MCAP>
addpath([pwd '/Mat']);
addpath([pwd '/Vec']);
addpath([pwd '/KSP']);
addpath([pwd '/PC'])

addpath([pwd '/util'])
addpath([pwd '/sys'])
addpath([pwd '/exe'])

if ~exist('mpi_Init', 'file')
    addpath([pwd '/mpi'])
end

if ~exist('m2c', 'file') && exist('../M2C', 'dir')
    % Starting from the current directory with M2C. Load M2C and compile.
    run ../M2C/startup
    
    if usejava('jvm')
        build_mpetsc;
    end
end

if exist('../MSPACK', 'dir')
    addpath([pwd '/../MSPACK'])
end

% Initialize PETSc automatically only when running without JVM
if ~usejava('jvm')
    load_mpetsc;
end
