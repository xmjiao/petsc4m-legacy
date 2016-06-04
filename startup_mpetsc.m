% Startup MPETSc module and compile some files automatically if needed.
mpetsc_root = fileparts(which('startup_mpetsc.m'));

addpath(mpetsc_root); %#ok<*MCAP>
addpath([mpetsc_root '/Mat']);
addpath([mpetsc_root '/Vec']);
addpath([mpetsc_root '/KSP']);
addpath([mpetsc_root '/PC']);

addpath([mpetsc_root '/util'])
addpath([mpetsc_root '/sys'])
addpath([mpetsc_root '/exe'])

if ~exist('m2c', 'file') && exist('../M2C', 'dir')
    % Start up M2C from its root directory
    run ../M2C/startup
    run ../MMPI/startup_mmpi
    run ../MSPACK/startup_mspack

    if ~exist(['petscFinalized.' mexext], 'file')
        % Prompt user how to build MPETSc if not yet built
        fprintf(1, ['To build MPETSc, use MATLAB/Octave command build_mpetsc_essential\n' ...
            'for basic functionality and build_mpetsc for all functionality.\n']);
    else
        % Try to load MPETSc automatically
        load_mpetsc;
    end
end
