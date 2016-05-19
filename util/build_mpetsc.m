function build_mpetsc(varargin)

build_mpetsc_essential(varargin{:});

%Compile the most most expensive top-level KSP wrapper functions with timing
opts = [{'-petsc', '-O3', '-mex', '-mexdir', 'mex'} varargin{:}];
files = {'mptKSPSetup', 'mptKSPSolve'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile other top-level wrapper functions without timing
opts = [{'-petsc', '-O3', '-mex', '-mexdir', 'mex'} varargin{:}];
files = {'mptKSPCleanup', 'mptMatCreateAIJFromCRS', 'mptMatAIJToCRS', ...
    'mptVecCreateFromArray', 'mptVecToArray'};
for i=1:length(files)
    m2c(opts{:}, files{i});
end

%Compile all other system-level and low-level functions with hidden mex files
opts = [{'-petsc', '-O', '-q', '-mex', '-mexdir', '../mex'} varargin{:}];
lines = [grep_pattern('sys/petscInitialize.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscFinalize.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscSplitOwnership.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscObjectGetComm.m', '\n%#codegen\s+-args'), ...
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
