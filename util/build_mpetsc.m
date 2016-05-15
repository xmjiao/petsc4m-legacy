function build_mpetsc(varargin)

opts = [{'-mex', '-O', '-petsc'} varargin{:}];

lines = [grep_pattern('petsc/petsc*.m', '\n%#codegen\s+-args') ...
    grep_pattern('util/petsc*.m', '\n%#codegen\s+-args') ...
    grep_pattern('sys/petsc*.m', '\n%#codegen\s+-args')];

if strfind(which('mpi_Init'), [pwd '/sys/mpi_Init'])
    % Add MPI calls
    lines = [lines, grep_pattern('sys/mpi_*.m', '\n%#codegen\s+-args')];
end

files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

for i=1:length(files)
    m2c(opts{:}, files{i}{1});
end

%Add timing for top-level functions
files = {'mptKSPCleanup' 'mptKSPSetup' 'mptKSPSolve'};
for i=1:length(files)
    m2c(opts{:}, '-time', files{i});
end


% TODO:
% MatGetDiagonal, MatAXPY, MatMult, MatMultAdd,
% MatMultTranspose, MatMultTransposeAdd, MatNorm, MatDiagonalScale,
% MatScale, MatTranspose, MatZeroEntries, MatShift, MatZeroEntries
%
% VecAXPY, VecAYPX, VecWAXPY, VecAXPBY, VecScale,
% VecDot, VecTDot,  VecDotBegin, VecDotEnd, VecNorm, VecNormBegin,
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
