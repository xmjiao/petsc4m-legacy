% Startup MPETSc module and compile some files automatically if needed.

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
        % Only build essential functions needed for code development
        % to speedup startup. The other functions will be built when
        % calling load_mpetsc.
        build_mpetsc_essential;
    else
        % Initialize PETSc automatically only when running without JVM
        load_mpetsc;
    end
end

if exist('../MSPACK', 'dir')
    addpath([pwd '/../MSPACK'])
end
