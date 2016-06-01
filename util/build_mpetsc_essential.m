function build_mpetsc_essential(varargin)

% Change to MPETSc's root directory to build.
mpetscroot = fileparts(which('startup_mpetsc'));
curpath = pwd;
cd(mpetscroot);

try    
    %Compile top-level functions for CRS and time top-level KSP functions
    if exist('octave_config_info', 'builtin')
        mexdir = {};
    else
        mexdir = {'mex'};
    end
    opts = [{'-petsc', '-exe', 'exe', '-mex'}, mexdir{:}, ...
        '-time', '{''mptKSPSetup'', ''mptKSPSolve''}', varargin{:}];
    m2c(opts{:}, 'mptSolveCRS');
    
    %Compile critical system-level functions into their own directory
    opts = [{'-petsc', '-O', '-mex'} varargin{:}];
    lines = [grep_pattern('sys/petscGet*.m', '\n%#codegen\s+-args'), ...
        grep_pattern('sys/petsc*ed.m', '\n%#codegen\s+-args')];
    files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
    for i=1:length(files)
        m2c(opts{:}, files{i}{1});
    end
    
    %Compile mpi functions into their own directory
    opts = [{'-petsc', '-O', '-mex'} varargin{:}];
    lines = grep_pattern('mpi/*.m', '\n%#codegen\s+-args');
    files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
    
    for i=1:length(files)
        m2c(opts{:}, files{i}{1});
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
