function build_mpetsc_essential(varargin)

opts = [{'-petsc', '-g', '-q', '-exe', '-exedir', 'exe', ...
    '-time', '{''mptKSPSetup'', ''mptKSPSolve''}'}, varargin{:}];

%Compile top-level functions for CRS and time top-level KSP functions
files = {'mptSolveCRS'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile utility functions into their own directory
opts = [{'-petsc', '-O', '-mex'} varargin{:}];
files = {'petscGetEnum.m', 'petscGetObject.m', 'petscGetString.m', ...
    'petscInitialized.m', 'petscFinalized.m'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile utility functions into their own directory
opts = [{'-petsc', '-O', '-mex'} varargin{:}];
lines = grep_pattern('mpi/*.m', '\n%#codegen\s+-args');
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end
