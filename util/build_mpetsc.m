function build_mpetsc(varargin)

% Change to MPETSc's root directory to build.
mpetscroot = fileparts(which('startup_mpetsc'));
curpath = pwd;
cd(mpetscroot);

try
    build_mpetsc_essential(varargin{:});
    
    %Compile the most most expensive top-level KSP wrapper functions with timing
    opts = [{'-petsc', '-O3', '-mex'} varargin{:}];
    files = {'mptKSPSetup', 'mptKSPSolve', 'mptKSPCleanup', 'mptMatCreateAIJFromCRS', ...
        'mptMatAIJToCRS', 'mptVecCreateFromArray', 'mptVecToArray'};
    
    if exist('octave_config_info', 'builtin')
        mexdir = {};
    else
        mexdir = {'-mexdir', 'mex'};
    end
    for i=1:length(files)
        m2c(opts{:}, mexdir{:}, files{i});
    end
    
    %Compile all other system-level and low-level functions with hidden mex files
    opts = [{'-petsc', '-O', '-mex'} varargin{:}];
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
    
    if exist('octave_config_info', 'builtin')
        mexdir = {};
    else
        mexdir = {'-mexdir', '../mex'};
    end
    for i=1:length(files)
        m2c(opts{:}, mexdir{:}, files{i}{1});
    end
    
    fprintf(1, '\nMPETsc was built successfully.\n\n');
    % Load MPETSc if successful
    load_mpetsc;
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);

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
