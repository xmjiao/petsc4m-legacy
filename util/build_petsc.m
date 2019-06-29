function build_petsc(varargin)

% Change to petsc's root directory to build.
curpath = pwd;
cd(petscroot);

try
    build_petsc_main(varargin{:});
catch
end

%Compile all other system-level and low-level functions with hidden mex files
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

mexdir = {'{''../mex/''}'};
opts = [{'-petsc', ['-I' petscroot '/include'], '-O3', '-mex'} mexdir{:}, varargin{:}];
for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

cd(curpath);
end

function build_petsc_main(varargin)

%Compile critical system-level functions into their own directory
opts = [{'-petsc', '-ckdep', '-O', '-mex'} varargin{:}];
lines = [grep_pattern('sys/petscGet*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petsc*ed.m', '\n%#codegen\s+-args')];
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

%Compile top-level functions for CRS and time top-level KSP functions
mexdir = {'{''../mex/''}'};
opts = [{'-petsc', '-ckdep', '-exe', '{''../exe/''}', '-mex'}, mexdir{:}, ...
    '-time', '{''petscKSPSetup'', ''petscKSPSolve''}', varargin{:}];
m2c(opts{:}, 'petscSolveCRS');

end
% TODO:
%
% 4.4.9 Multigrid Preconditioners
% PCMGSetLevels, PCMGSetType, PCMGSetCycleType, PCMGSetNumberSmoothUp,
% PCMGSetNumberSmoothDown, PCMGGetCoarseSolve, PCMGGetSmoother,
% PCMGGetSmootherUp, PCMGGetSmootherDown, PCMGSetInterpolation,
% PCMGSetRestriction,
% Optional work vectors for PC: PCMGSetRhs, PCMGSetX, PCMGSetR
%
% MatDiagonalScale, MatScale,
% MatTranspose, MatZeroEntries, MatShift, MatZeroEntries,
% MatCreateTranspose, MatCreateNormal, MatIsTranspose,
% MatIsSymmetric, MatIsHermitian
%
% VecWAXPY, VecAXPBY, VecScale,
% VecDot, VecTDot,  VecDotBegin, VecDotEnd, VecNormBegin,
% VecNormEnd, VecSum, VecCopy, VecSwap, VecPointwiseMult,
% VecPointwiseDivide, VecMDot, VecMTDOt, VecMAXPTY, VecMax, VecMin,
% VecAbs, VecReciprocal, VecShift, VecSet.
%
% MatCholeskyFactor, MatLUFactor, MatGetFactor, MatReorderForNonzeroDiagonal
%
% petscMatCreateAIJ, petscVecCreateMPI,
% MatGetType, MatCreateMPIAIJWithArrays, MatCreateSeqAIJWithArrays
% MatMPIAIJSetPreallocation, MatSeqAIJSetPreallocation
%
% PCGetOperators, KSPGetOperators

% Unsupported: KSPRegister, PCRegister
