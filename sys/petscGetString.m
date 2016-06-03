function [str, toplevel] = petscGetString(name)
%petscGetObject Obtain an opaque object in PETSC
%
%    str = petscGetObject(name)
%
%The supported names include:
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatType.html
% MatType:  MATSAME, MATMAIJ, MATSEQMAIJ, MATMPIMAIJ, MATIS, MATAIJ,
%     MATSEQAIJ, MATMPIAIJ, MATAIJCRL, MATSEQAIJCRL, MATMPIAIJCRL,
%     MATAIJCUSP, MATSEQAIJCUSP, MATMPIAIJCUSP, MATAIJCUSPARSE,
%     MATSEQAIJCUSPARSE, MATMPIAIJCUSPARSE, MATAIJVIENNACL,
%     MATSEQAIJVIENNACL, MATMPIAIJVIENNACL, MATAIJPERM,
%     MATSEQAIJPERM, MATMPIAIJPERM, MATSHELL, MATDENSE,
%     MATSEQDENSE, MATMPIDENSE, MATELEMENTAL, MATBAIJ,
%     MATSEQBAIJ, MATMPIBAIJ, MATMPIADJ, MATSBAIJ, MATSEQSBAIJ,
%     MATMPISBAIJ, MATSEQBSTRM, MATMPIBSTRM, MATBSTRM, MATSEQSBSTRM,
%     MATMPISBSTRM, MATSBSTRM, MATDAAD, MATMFFD, MATNORMAL,
%     MATNORMALHERMITIAN, MATLRC, MATSCATTER, MATBLOCKMAT,
%     MATCOMPOSITE, MATFFT, MATFFTW, MATSEQCUFFT, MATTRANSPOSEMAT,
%     MATSCHURCOMPLEMENT, MATPYTHON, MATHYPRESTRUCT, MATHYPRESSTRUCT,
%     MATSUBMATRIX, MATLOCALREF, MATNEST, MATPREALLOCATOR
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecType.html
% VecType: VECSEQ, VECMPI, VECSTANDARD, VECSHARED, VECSEQCUSP,
%          VECMPICUSP, VECCUSP, VECSEQVIENNACL, VECMPIVIENNACL,
%          VECVIENNACL, VECSEQCUDA, VECMPICUDA, VECCUDA, VECNEST
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPType.html
% KSPType: KSPRICHARDSON, KSPCHEBYSHEV, KSPCG, KSPGROPPCG,
%     KSPPIPECG, KSPPIPECGRR, KSPCGNE, KSPNASH,
%     KSPSTCG, KSPGLTR, KSPFCG, KSPPIPEFCG, KSPGMRES,
%     KSPPIPEFGMRES, KSPFGMRES, KSPLGMRES, KSPDGMRES,
%     KSPPGMRES, KSPTCQMR, KSPBCGS, KSPIBCGS, KSPFBCGS,
%     KSPFBCGSR, KSPBCGSL, KSPCGS, KSPTFQMR, KSPCR, KSPPIPECR,
%     KSPLSQR, KSPPREONLY, KSPQCG, KSPBICG, KSPMINRES, KSPSYMMLQ,
%     KSPLCD, KSPPYTHON, KSPGCR, KSPPIPEGCR, KSPTSIRM, KSPCGLS
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCType.html
% PCType: PCNONE, PCJACOBI, PCSOR, PCLU, PCSHELL, PCBJACOBI, PCMG,
%     PCEISENSTAT, PCILU, PCICC, PCASM, PCGASM, PCKSP, PCCOMPOSITE,
%     PCREDUNDANT, PCSPAI, PCNN, PCCHOLESKY, PCPBJACOBI, PCMAT, PCHYPRE,
%     PCPARMS, PCFIELDSPLIT, PCTFS, PCML, PCGALERKIN, PCEXOTIC, PCCP,
%     PCBFBT, PCLSC, PCPYTHON, PCPFMG, PCSYSPFMG, PCREDISTRIBUTE, PCSVD,
%     PCGAMG, PCSACUSP, PCSACUSPPOLY, PCBICGSTABCUSP, PCAINVCUSP,
%     PCBDDC, PCKACZMARZ, PCTELESCOPE
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSolverPackage.html
% MatSolverPackage: MatSolverPackage, MATSOLVERSUPERLU, MATSOLVERSUPERLU_DIST,
%    MATSOLVERUMFPACK, MATSOLVERCHOLMOD, MATSOLVERCLIQUE, MATSOLVERKLU,
%    MATSOLVERELEMENTAL, MATSOLVERESSL, MATSOLVERLUSOL, MATSOLVERMUMPS,
%    MATSOLVERMKL_PARDISO, MATSOLVERMKL_CPARDISO, MATSOLVERPASTIX.
%    MATSOLVERMATLAB, MATSOLVERPETSC, MATSOLVERBAS, MATSOLVERCUSPARSE.
%    MATSOLVERBSTRM, MATSOLVERSBSTRM
%
% Other: PETSC_NULL_STRING

%#codegen -args {coder.typeof(char(0),[1,inf])}
coder.cinclude('mpetsc.h');

if isempty(coder.target)
    error('Function petscGetObject must be compiled.');
end

switch name
    case 'PETSC_NULL_STRING'
        [str, toplevel] = get_string('const char *', 'NULL', nargout>1);
    case 'MATSAME'
        [str, toplevel] = get_string('MatType', 'MATSAME', nargout>1);
    case 'MATMAIJ'
        [str, toplevel] = get_string('MatType', 'MATMAIJ', nargout>1);
    case 'MATSEQMAIJ'
        [str, toplevel] = get_string('MatType', 'MATSEQMAIJ', nargout>1);
    case 'MATMPIMAIJ'
        [str, toplevel] = get_string('MatType', 'MATMPIMAIJ', nargout>1);
    case 'MATIS'
        [str, toplevel] = get_string('MatType', 'MATIS', nargout>1);
    case 'MATAIJ'
        [str, toplevel] = get_string('MatType', 'MATAIJ', nargout>1);
    case 'MATSEQAIJ'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJ', nargout>1);
    case 'MATMPIAIJ'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJ', nargout>1);
    case 'MATAIJCRL'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJ', nargout>1);
    case 'MATSEQAIJCRL'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJCRL', nargout>1);
    case 'MATMPIAIJCRL'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJCRL', nargout>1);
    case 'MATAIJCUSP'
        [str, toplevel] = get_string('MatType', 'MATAIJCUSP', nargout>1);
    case 'MATSEQAIJCUSP'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJCUSP', nargout>1);
    case 'MATMPIAIJCUSP'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJCUSP', nargout>1);
    case 'MATAIJCUSPARSE'
        [str, toplevel] = get_string('MatType', 'MATAIJCUSPARSE', nargout>1);
    case 'MATSEQAIJCUSPARSE'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJCUSPARSE', nargout>1);
    case 'MATMPIAIJCUSPARSE'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJCUSPARSE', nargout>1);
    case 'MATAIJVIENNACL'
        [str, toplevel] = get_string('MatType', 'MATAIJVIENNACL', nargout>1);
    case 'MATSEQAIJVIENNACL'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJVIENNACL', nargout>1);
    case 'MATMPIAIJVIENNACL'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJVIENNACL', nargout>1);
    case 'MATAIJPERM'
        [str, toplevel] = get_string('MatType', 'MATAIJPERM', nargout>1);
    case 'MATSEQAIJPERM'
        [str, toplevel] = get_string('MatType', 'MATSEQAIJPERM', nargout>1);
    case 'MATMPIAIJPERM'
        [str, toplevel] = get_string('MatType', 'MATMPIAIJPERM', nargout>1);
    case 'MATSHELL'
        [str, toplevel] = get_string('MatType', 'MATSHELL', nargout>1);
    case 'MATDENSE'
        [str, toplevel] = get_string('MatType', 'MATDENSE', nargout>1);
    case 'MATSEQDENSE'
        [str, toplevel] = get_string('MatType', 'MATSEQDENSE', nargout>1);
    case 'MATMPIDENSE'
        [str, toplevel] = get_string('MatType', 'MATMPIDENSE', nargout>1);
    case 'MATELEMENTAL'
        [str, toplevel] = get_string('MatType', 'MATELEMENTAL', nargout>1);
    case 'MATBAIJ'
        [str, toplevel] = get_string('MatType', 'MATBAIJ', nargout>1);
    case 'MATSEQBAIJ'
        [str, toplevel] = get_string('MatType', 'MATSEQBAIJ', nargout>1);
    case 'MATMPIBAIJ'
        [str, toplevel] = get_string('MatType', 'MATMPIBAIJ', nargout>1);
    case 'MATMPIADJ'
        [str, toplevel] = get_string('MatType', 'MATMPIADJ', nargout>1);
    case 'MATSBAIJ'
        [str, toplevel] = get_string('MatType', 'MATSBAIJ', nargout>1);
    case 'MATSEQSBAIJ'
        [str, toplevel] = get_string('MatType', 'MATSEQSBAIJ', nargout>1);
    case 'MATMPISBAIJ'
        [str, toplevel] = get_string('MatType', 'MATMPISBAIJ', nargout>1);
    case 'MATSEQBSTRM'
        [str, toplevel] = get_string('MatType', 'MATSEQBSTRM', nargout>1);
    case 'MATMPIBSTRM'
        [str, toplevel] = get_string('MatType', 'MATMPIBSTRM', nargout>1);
    case 'MATBSTRM'
        [str, toplevel] = get_string('MatType', 'MATBSTRM', nargout>1);
    case 'MATSEQSBSTRM'
        [str, toplevel] = get_string('MatType', 'MATSEQSBSTRM', nargout>1);
    case 'MATMPISBSTRM'
        [str, toplevel] = get_string('MatType', 'MATMPISBSTRM', nargout>1);
    case 'MATSBSTRM'
        [str, toplevel] = get_string('MatType', 'MATSBSTRM', nargout>1);
    case 'MATDAAD'
        [str, toplevel] = get_string('MatType', 'MATDAAD', nargout>1);
    case 'MATMFFD'
        [str, toplevel] = get_string('MatType', 'MATMFFD', nargout>1);
    case 'MATNORMAL'
        [str, toplevel] = get_string('MatType', 'MATNORMAL', nargout>1);
    case 'MATNORMALHERMITIAN'
        [str, toplevel] = get_string('MatType', 'MATNORMALHERMITIAN', nargout>1);
    case 'MATLRC'
        [str, toplevel] = get_string('MatType', 'MATLRC', nargout>1);
    case 'MATSCATTER'
        [str, toplevel] = get_string('MatType', 'MATSCATTER', nargout>1);
    case 'MATBLOCKMAT'
        [str, toplevel] = get_string('MatType', 'MATBLOCKMAT', nargout>1);
    case 'MATCOMPOSITE'
        [str, toplevel] = get_string('MatType', 'MATCOMPOSITE', nargout>1);
    case 'MATFFT'
        [str, toplevel] = get_string('MatType', 'MATFFT', nargout>1);
    case 'MATFFTW'
        [str, toplevel] = get_string('MatType', 'MATFFTW', nargout>1);
    case 'MATSEQCUFFT'
        [str, toplevel] = get_string('MatType', 'MATSEQCUFFT', nargout>1);
    case 'MATTRANSPOSEMAT'
        [str, toplevel] = get_string('MatType', 'MATTRANSPOSEMAT', nargout>1);
    case 'MATSCHURCOMPLEMENT'
        [str, toplevel] = get_string('MatType', 'MATSCHURCOMPLEMENT', nargout>1);
    case 'MATPYTHON'
        [str, toplevel] = get_string('MatType', 'MATPYTHON', nargout>1);
    case 'MATHYPRESTRUCT'
        [str, toplevel] = get_string('MatType', 'MATHYPRESTRUCT', nargout>1);
    case 'MATHYPRESSTRUCT'
        [str, toplevel] = get_string('MatType', 'MATHYPRESSTRUCT', nargout>1);
    case 'MATSUBMATRIX'
        [str, toplevel] = get_string('MatType', 'MATSUBMATRIX', nargout>1);
    case 'MATLOCALREF'
        [str, toplevel] = get_string('MatType', 'MATSUBMATRIX', nargout>1);
    case 'MATNEST'
        [str, toplevel] = get_string('MatType', 'MATNEST', nargout>1);
    case 'MATPREALLOCATOR'
        [str, toplevel] = get_string('MatType', 'MATPREALLOCATOR', nargout>1);
    case 'VECSEQ'
        [str, toplevel] = get_string('VecType', 'VECSEQ', nargout>1);
    case 'VECMPI'
        [str, toplevel] = get_string('VecType', 'VECMPI', nargout>1);
    case 'VECSTANDARD'
        [str, toplevel] = get_string('VecType', 'VECSTANDARD', nargout>1);
    case 'VECSHARED'
        [str, toplevel] = get_string('VecType', 'VECSHARED', nargout>1);
    case 'VECSEQCUSP'
        [str, toplevel] = get_string('VecType', 'VECSEQCUSP', nargout>1);
    case 'VECMPICUSP'
        [str, toplevel] = get_string('VecType', 'VECMPICUSP', nargout>1);
    case 'VECCUSP'
        [str, toplevel] = get_string('VecType', 'VECCUSP', nargout>1);
    case 'VECSEQVIENNACL'
        [str, toplevel] = get_string('VecType', 'VECSEQVIENNACL', nargout>1);
    case 'VECMPIVIENNACL'
        [str, toplevel] = get_string('VecType', 'VECMPIVIENNACL', nargout>1);
    case 'VECVIENNACL'
        [str, toplevel] = get_string('VecType', 'VECVIENNACL', nargout>1);
    case 'VECSEQCUDA'
        [str, toplevel] = get_string('VecType', 'VECSEQCUDA', nargout>1);
    case 'VECMPICUDA'
        [str, toplevel] = get_string('VecType', 'VECMPICUDA', nargout>1);
    case 'VECCUDA'
        [str, toplevel] = get_string('VecType', 'VECCUDA', nargout>1);
    case 'VECNEST'
        [str, toplevel] = get_string('VecType', 'VECNEST', nargout>1);
    case 'KSPRICHARDSON'
        [str, toplevel] = get_string('KSPType', 'KSPRICHARDSON', nargout>1);
    case 'KSPCHEBYSHEV'
        [str, toplevel] = get_string('KSPType', 'KSPCHEBYSHEV', nargout>1);
    case 'KSPCG'
        [str, toplevel] = get_string('KSPType', 'KSPCG', nargout>1);
    case 'KSPGROPPCG'
        [str, toplevel] = get_string('KSPType', 'KSPGROPPCG', nargout>1);
    case 'KSPPIPECG'
        [str, toplevel] = get_string('KSPType', 'KSPPIPECG', nargout>1);
    case 'KSPPIPECGRR'
        [str, toplevel] = get_string('KSPType', 'KSPPIPECGRR', nargout>1);
    case 'KSPCGNE'
        [str, toplevel] = get_string('KSPType', 'KSPCGNE', nargout>1);
    case 'KSPNASH'
        [str, toplevel] = get_string('KSPType', 'KSPNASH', nargout>1);
    case 'KSPSTCG'
        [str, toplevel] = get_string('KSPType', 'KSPSTCG', nargout>1);
    case 'KSPGLTR'
        [str, toplevel] = get_string('KSPType', 'KSPGLTR', nargout>1);
    case 'KSPFCG'
        [str, toplevel] = get_string('KSPType', 'KSPFCG', nargout>1);
    case 'KSPPIPEFCG'
        [str, toplevel] = get_string('KSPType', 'KSPPIPEFCG', nargout>1);
    case 'KSPGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPGMRES', nargout>1);
    case 'KSPPIPEFGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPPIPEFGMRES', nargout>1);
    case 'KSPFGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPFGMRES', nargout>1);
    case 'KSPLGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPLGMRES', nargout>1);
    case 'KSPDGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPDGMRES', nargout>1);
    case 'KSPPGMRES'
        [str, toplevel] = get_string('KSPType', 'KSPPGMRES', nargout>1);
    case 'KSPTCQMR'
        [str, toplevel] = get_string('KSPType', 'KSPTCQMR', nargout>1);
    case 'KSPBCGS'
        [str, toplevel] = get_string('KSPType', 'KSPBCGS', nargout>1);
    case 'KSPIBCGS'
        [str, toplevel] = get_string('KSPType', 'KSPIBCGS', nargout>1);
    case 'KSPFBCGS'
        [str, toplevel] = get_string('KSPType', 'KSPFBCGS', nargout>1);
    case 'KSPFBCGSR'
        [str, toplevel] = get_string('KSPType', 'KSPFBCGSR', nargout>1);
    case 'KSPBCGSL'
        [str, toplevel] = get_string('KSPType', 'KSPBCGSL', nargout>1);
    case 'KSPCGS'
        [str, toplevel] = get_string('KSPType', 'KSPCGS', nargout>1);
    case 'KSPTFQMR'
        [str, toplevel] = get_string('KSPType', 'KSPTFQMR', nargout>1);
    case 'KSPCR'
        [str, toplevel] = get_string('KSPType', 'KSPCR', nargout>1);
    case 'KSPPIPECR'
        [str, toplevel] = get_string('KSPType', 'KSPPIPECR', nargout>1);
    case 'KSPLSQR'
        [str, toplevel] = get_string('KSPType', 'KSPLSQR', nargout>1);
    case 'KSPPREONLY'
        [str, toplevel] = get_string('KSPType', 'KSPPREONLY', nargout>1);
    case 'KSPQCG'
        [str, toplevel] = get_string('KSPType', 'KSPQCG', nargout>1);
    case 'KSPBICG'
        [str, toplevel] = get_string('KSPType', 'KSPBICG', nargout>1);
    case 'KSPMINRES'
        [str, toplevel] = get_string('KSPType', 'KSPMINRES', nargout>1);
    case 'KSPSYMMLQ'
        [str, toplevel] = get_string('KSPType', 'KSPSYMMLQ', nargout>1);
    case 'KSPLCD'
        [str, toplevel] = get_string('KSPType', 'KSPLCD', nargout>1);
    case 'KSPPYTHON'
        [str, toplevel] = get_string('KSPType', 'KSPPYTHON', nargout>1);
    case 'KSPGCR'
        [str, toplevel] = get_string('KSPType', 'KSPGCR', nargout>1);
    case 'KSPPIPEGCR'
        [str, toplevel] = get_string('KSPType', 'KSPPIPEGCR', nargout>1);
    case 'KSPTSIRM'
        [str, toplevel] = get_string('KSPType', 'KSPTSIRM', nargout>1);
    case 'KSPCGLS'
        [str, toplevel] = get_string('KSPType', 'KSPCGLS', nargout>1);
    case 'PCNONE'
        [str, toplevel] = get_string('PCType', 'PCNONE', nargout>1);
    case 'PCJACOBI'
        [str, toplevel] = get_string('PCType', 'PCJACOBI', nargout>1);
    case 'PCSOR'
        [str, toplevel] = get_string('PCType', 'PCSOR', nargout>1);
    case 'PCLU'
        [str, toplevel] = get_string('PCType', 'PCLU', nargout>1);
    case 'PCSHELL'
        [str, toplevel] = get_string('PCType', 'PCSHELL', nargout>1);
    case 'PCBJACOBI'
        [str, toplevel] = get_string('PCType', 'PCBJACOBI', nargout>1);
    case 'PCMG'
        [str, toplevel] = get_string('PCType', 'PCMG', nargout>1);
    case 'PCEISENSTAT'
        [str, toplevel] = get_string('PCType', 'PCEISENSTAT', nargout>1);
    case 'PCILU'
        [str, toplevel] = get_string('PCType', 'PCILU', nargout>1);
    case 'PCICC'
        [str, toplevel] = get_string('PCType', 'PCICC', nargout>1);
    case 'PCASM'
        [str, toplevel] = get_string('PCType', 'PCASM', nargout>1);
    case 'PCGASM'
        [str, toplevel] = get_string('PCType', 'PCGASM', nargout>1);
    case 'PCKSP'
        [str, toplevel] = get_string('PCType', 'PCKSP', nargout>1);
    case 'PCCOMPOSITE'
        [str, toplevel] = get_string('PCType', 'PCCOMPOSITE', nargout>1);
    case 'PCREDUNDANT'
        [str, toplevel] = get_string('PCType', 'PCREDUNDANT', nargout>1);
    case 'PCSPAI'
        [str, toplevel] = get_string('PCType', 'PCSPAI', nargout>1);
    case 'PCNN'
        [str, toplevel] = get_string('PCType', 'PCNN', nargout>1);
    case 'PCCHOLESKY'
        [str, toplevel] = get_string('PCType', 'PCCHOLESKY', nargout>1);
    case 'PCPBJACOBI'
        [str, toplevel] = get_string('PCType', 'PCPBJACOBI', nargout>1);
    case 'PCMAT'
        [str, toplevel] = get_string('PCType', 'PCMAT', nargout>1);
    case 'PCHYPRE'
        [str, toplevel] = get_string('PCType', 'PCHYPRE', nargout>1);
    case 'PCPARMS'
        [str, toplevel] = get_string('PCType', 'PCPARMS', nargout>1);
    case 'PCFIELDSPLIT'
        [str, toplevel] = get_string('PCType', 'PCFIELDSPLIT', nargout>1);
    case 'PCTFS'
        [str, toplevel] = get_string('PCType', 'PCTFS', nargout>1);
    case 'PCML'
        [str, toplevel] = get_string('PCType', 'PCML', nargout>1);
    case 'PCGALERKIN'
        [str, toplevel] = get_string('PCType', 'PCGALERKIN', nargout>1);
    case 'PCEXOTIC'
        [str, toplevel] = get_string('PCType', 'PCEXOTIC', nargout>1);
    case 'PCCP'
        [str, toplevel] = get_string('PCType', 'PCCP', nargout>1);
    case 'PCBFBT'
        [str, toplevel] = get_string('PCType', 'PCBFBT', nargout>1);
    case 'PCLSC'
        [str, toplevel] = get_string('PCType', 'PCLSC', nargout>1);
    case 'PCPYTHON'
        [str, toplevel] = get_string('PCType', 'PCPYTHON', nargout>1);
    case 'PCPFMG'
        [str, toplevel] = get_string('PCType', 'PCPFMG', nargout>1);
    case 'PCSYSPFMG'
        [str, toplevel] = get_string('PCType', 'PCSYSPFMG', nargout>1);
    case 'PCREDISTRIBUTE'
        [str, toplevel] = get_string('PCType', 'PCREDISTRIBUTE', nargout>1);
    case 'PCSVD'
        [str, toplevel] = get_string('PCType', 'PCSVD', nargout>1);
    case 'PCGAMG'
        [str, toplevel] = get_string('PCType', 'PCGAMG', nargout>1);
    case 'PCSACUSP'
        [str, toplevel] = get_string('PCType', 'PCSACUSP', nargout>1);
    case 'PCSACUSPPOLY'
        [str, toplevel] = get_string('PCType', 'PCSACUSPPOLY', nargout>1);
    case 'PCBICGSTABCUSP'
        [str, toplevel] = get_string('PCType', 'PCBICGSTABCUSP', nargout>1);
    case 'PCAINVCUSP'
        [str, toplevel] = get_string('PCType', 'PCAINVCUSP', nargout>1);
    case 'PCBDDC'
        [str, toplevel] = get_string('PCType', 'PCBDDC', nargout>1);
    case 'PCKACZMARZ'
        [str, toplevel] = get_string('PCType', 'PCKACZMARZ', nargout>1);
    case 'PCTELESCOPE'
        [str, toplevel] = get_string('PCType', 'PCTELESCOPE', nargout>1);
    case 'MATSOLVERSUPERLU'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERSUPERLU', nargout>1);
    case 'MATSOLVERSUPERLU_DIST'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERSUPERLU_DIST', nargout>1);
    case 'MATSOLVERUMFPACK'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERUMFPACK', nargout>1);
    case 'MATSOLVERCHOLMOD'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERCHOLMOD', nargout>1);
    case 'MATSOLVERCLIQUE'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERCLIQUE', nargout>1);
    case 'MATSOLVERKLU'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERKLU', nargout>1);
    case 'MATSOLVERELEMENTAL'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERELEMENTAL', nargout>1);
    case 'MATSOLVERESSL'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERESSL', nargout>1);
    case 'MATSOLVERLUSOL'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERLUSOL', nargout>1);
    case 'MATSOLVERMUMPS'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERMUMPS', nargout>1);
    case 'MATSOLVERMKL_PARDISO'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERMKL_PARDISO', nargout>1);
    case 'MATSOLVERMKL_CPARDISO'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERMKL_CPARDISO', nargout>1);
    case 'MATSOLVERPASTIX'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERPASTIX', nargout>1);
    case 'MATSOLVERMATLAB'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERMATLAB', nargout>1);
    case 'MATSOLVERPETSC'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERPETSC', nargout>1);
    case 'MATSOLVERBAS'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERBAS', nargout>1);
    case 'MATSOLVERCUSPARSE'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERCUSPARSE', nargout>1);
    case 'MATSOLVERBSTRM'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERBSTRM', nargout>1);
    case 'MATSOLVERSBSTRM'
        [str, toplevel] = get_string('const MatSolverPackage', 'MATSOLVERSBSTRM', nargout>1);
    otherwise
        m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
        if nargout>1
            str = char(0,1);
            toplevel = true;
        end
end
end

function [str, toplevel] = get_string(type, name, toplevel)
coder.inline('always')

str0 = coder.opaque(type, name);

if ~toplevel
    str = str0;
else
    str = m2c_strcopy(str0, 'wrap');
end
end
