function build_petsc(varargin)

% Check PETSC_DIR
PETSC_DIR=getenv('PETSC_DIR');
if isempty(PETSC_DIR) && exist('/usr/lib/petsc', 'dir')
    PETSC_DIR = '/usr/lib/petsc';
end

configure_file = fullfile(PETSC_DIR, 'lib', 'petsc', 'conf', 'petscvariables');
try
    conf = fileread(configure_file);
catch
    error('You must define $PETSC_DIR with a valid file $PETSC_DIR/lib/petsc/conf/petscvariables.');
end
if contains(conf, '--with-precision=single') ~= isa(PetscReal(0), 'single')
    error(['Petsc4m is for ' class(PetscReal(0)) ' precision but PETSC_DIR points to an incompatible version.', newline, ...
        'Please PETSC_DIR, e.g. by unloading petsc and loading a compatible module.']);
end

% Change to petsc's root directory to build.
curpath = pwd;
cd(petscroot);

build_petsc_main(curpath, varargin{:});

%Compile all other system-level and low-level functions with hidden mex files
lines = [grep_pattern('sys/petscInitialize.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscFinalize.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscSplitOwnership.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petscObjectGetComm.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petsc*Options*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('Mat/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('Vec/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('KSP/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('PC/petsc*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('CRS/petscMat*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('hypreApply.m', '\n%#codegen\s+-args')];
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

opts = [{'-petsc', ['-I' petscroot '/include'], '-O3', '-mex'}, varargin{:}];
opts_nowarn = [{'-petsc', ['-I' petscroot '/include'], '-O3', '-mex', ...
    '-cflags', '{''-Wno-incompatible-pointer-types''}'}, varargin{:}];
for i=1:length(files)
    try
        if strcmp(files{i}{1}, 'KSP/petscKSPGetResidualHistory.m')
            m2c(opts_nowarn{:}, files{i}{1});
        else
            m2c(opts{:}, files{i}{1});
        end
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME)
        end
    end
end

cd(curpath);
end

function build_petsc_main(curpath, varargin)

%Compile critical system-level functions into their own directory
opts = [{'-petsc', '-ckdep', '-O', '-mex'} varargin{:}];
lines = [grep_pattern('sys/petscGet*.m', '\n%#codegen\s+-args'), ...
    grep_pattern('sys/petsc*ed.m', '\n%#codegen\s+-args')];
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');
for i=1:length(files)
    try
        m2c(opts{:}, files{i}{1});
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME)
        end
    end
end

%Compile top-level functions for CRS and time top-level KSP functions
if isoctave
    opts = [{'-petsc', '-ckdep', '-mex', ...
        '-cflags', '{''-Wno-incompatible-pointer-types''}', ...
        '-time', '{''petscKSPSetup'', ''petscKSPSolve''}'}, varargin{:}];
else
    opts = [{'-petsc', '-ckdep', '-exe', '{''../exe/''}', ...
        '-cflags', '{''-Wno-incompatible-pointer-types''}', ...
        '-time', '{''petscKSPSetup'', ''petscKSPSolve''}'}, varargin{:}];
end
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
% MatDiagonalScale, MatTranspose, MatZeroEntries, MatZeroEntries,
% MatCreateTranspose, MatCreateNormal, MatIsTranspose,
% MatIsSymmetric, MatIsHermitian
%
% VecWAXPY, VecAXPBY, VecTDot,  VecDotBegin, VecDotEnd, VecNormBegin,
% VecNormEnd, VecSum, VecSwap, VecPointwiseMult,
% VecPointwiseDivide, VecMDot, VecMTDOt, VecMAXPTY, VecMax, VecMin,
% VecAbs, VecReciprocal
%
% MatCholeskyFactor, MatLUFactor, MatGetFactor, MatReorderForNonzeroDiagonal
%
% petscMatCreateAIJ, petscVecCreateMPI,
% MatGetType, MatCreateMPIAIJWithArrays, MatCreateSeqAIJWithArrays
% MatMPIAIJSetPreallocation, MatSeqAIJSetPreallocation

% Unsupported: KSPRegister, PCRegister
