function build_mpetsc(varargin)

opts = [{'-petsc', '-g', '-exe', '-exedir', 'exe', ...
    '-time', '{''mptKSPCleanup'', ''mptKSPSetup'', ''mptKSPSolve''}'}, varargin{:}];

%Compile top-level functions for CRS and time top-level KSP functions
files = {'mptSolveCRS'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile top-level wrapper functions and add timing
opts = [{'-petsc', '-O3', '-time', '-mex', '-mexdir', 'mex'} varargin{:}];
lines = grep_pattern('mpt[KMV]*.m', '\n%#codegen\s+-args');
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

%Compile utility functions.
opts = [{'-petsc', '-O', '-mex'} varargin{:}];
files = {'petscGetEnum.m', 'petscGetObject.m', 'petscGetString.m', ...
    'petscSplitOwnership.m', 'petscInitialized.m', 'petscFinalized.m'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile mpi functions.
opts = [{'-petsc', '-O', '-mex'} varargin{:}];
lines = grep_pattern('mpi/*.m', '\n%#codegen\s+-args');
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

%Compile all other system-level and low-level functions with hidden mex files
opts = [{'-petsc', '-O', '-q', '-mex', '-mexdir', '../mex'} varargin{:}];
lines = [grep_pattern('sys/petsc[IF]*e.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petsc*Options*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('Mat/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('Vec/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('KSP/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('PC/petsc*.m', '\n%#codegen\s+-args')];
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

% TODO:
% MatDiagonalScale,
% MatScale, MatTranspose, MatZeroEntries, MatShift, MatZeroEntries
%
% VecWAXPY, VecAXPBY, VecScale,
% VecDot, VecTDot,  VecDotBegin, VecDotEnd, VecNormBegin,
% VecNormEnd, VecSum, VecCopy, VecSwap, VecPointwiseMult,
% VecPointwiseDivide, VecMDot, VecMTDOt, VeccMAXPTY, VecMax, VecMin,
% VecAbs, VecReciprocal, VecShift, VecSet.
%
% MatNullSpace, MatNullSpaceCreate,
%
% MatCholeskyFactor, MatLUFactor, MatGetFactor, MatReorderForNonzeroDiagonal
%
% , petscMatCreateAIJ, petscVecCreateMPI,
% MatGetType, MatCreateMPIAIJWithArrays, MatCreateSeqAIJWithArrays
% MatMPIAIJSetPreallocation, MatSeqAIJSetPreallocation
% MatSetNullSpace() and MatSetTransposeNullSpace()
% PCGetOperators, KSPGetOperators

% Unsupported: KSPRegister, PCRegister
