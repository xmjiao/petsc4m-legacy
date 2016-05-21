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
    
    if ~exist(['petscFinalized.' mexext], 'file')
        fprintf(1, ['To build MPETSc, use MATLAB/Octave command build_mpetsc_essential' ...
            'for basic functionality and build_mpetsc for all functionality.\n']);
    elseif ~usejava('jvm') || exist('octave_config_info', 'builtin')
        load_mpetsc;
    end
end

if exist('../MSPACK', 'dir')
    addpath([pwd '/../MSPACK'])
end
