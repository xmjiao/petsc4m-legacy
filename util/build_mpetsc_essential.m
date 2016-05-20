function build_mpetsc_essential(varargin)

% Change to MPETSc's root directory to build.
mpetscroot = fileparts(which('startup_mpetsc'));
curpath = pwd;
cd(mpetscroot);

try
    opts = [{'-petsc', '-g', '-exe', '-exedir', 'exe', ...
        '-time', '{''mptKSPSetup'', ''mptKSPSolve''}'}, varargin{:}];
    
    %Compile top-level functions for CRS and time top-level KSP functions
    files = {'mptSolveCRS'};
    for i=1:length(files)
        m2c(opts{:}, files{i});
    end
    
    %Compile critical system-level functions into their own directory
    opts = [{'-petsc', '-O', '-mex'} varargin{:}];
    files = {'sys/petscGetEnum.m', 'sys/petscGetObject.m', 'sys/petscGetString.m', ...
        'sys/petscInitialized.m', 'sys/petscFinalized.m'};
    for i=1:length(files)
        m2c(opts{:}, files{i});
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
