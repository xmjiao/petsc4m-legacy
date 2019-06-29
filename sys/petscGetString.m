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
%     MATAIJCUSPARSE, MATSEQAIJCUSPARSE, MATMPIAIJCUSPARSE, MATAIJVIENNACL,
%     MATSEQAIJVIENNACL, MATMPIAIJVIENNACL, MATAIJPERM,
%     MATSEQAIJPERM, MATMPIAIJPERM, MATSHELL, MATDENSE,
%     MATSEQDENSE, MATMPIDENSE, MATELEMENTAL, MATBAIJ,
%     MATSEQBAIJ, MATMPIBAIJ, MATMPIADJ, MATSBAIJ, MATSEQSBAIJ,
%     MATMPISBAIJ, MATDAAD, MATMFFD, MATNORMAL,
%     MATNORMALHERMITIAN, MATLRC, MATSCATTER, MATBLOCKMAT,
%     MATCOMPOSITE, MATFFT, MATFFTW, MATSEQCUFFT, MATTRANSPOSEMAT,
%     MATSCHURCOMPLEMENT, MATPYTHON, MATHYPRESTRUCT, MATHYPRESSTRUCT,
%     MATSUBMATRIX, MATLOCALREF, MATNEST, MATPREALLOCATOR
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecType.html
% VecType: VECSEQ, VECMPI, VECSTANDARD, VECSHARED,
%          VECSEQVIENNACL, VECMPIVIENNACL,
%          VECVIENNACL, VECSEQCUDA, VECMPICUDA, VECCUDA, VECNEST
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPType.html
% KSPType: KSPRICHARDSON, KSPCHEBYSHEV, KSPCG, KSPGROPPCG,
%     KSPPIPECG, KSPPIPECGRR, KSPCGNE,
%     KSPFCG, KSPPIPEFCG, KSPGMRES,
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
%     PCGAMG, PCBDDC, PCKACZMARZ, PCTELESCOPE
%
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSolverType.html
% MatSolverType: MATSOLVERSUPERLU, MATSOLVERSUPERLU_DIST,
%    MATSOLVERUMFPACK, MATSOLVERCHOLMOD, MATSOLVERKLU,
%    MATSOLVERELEMENTAL, MATSOLVERESSL, MATSOLVERLUSOL, MATSOLVERMUMPS,
%    MATSOLVERMKL_PARDISO, MATSOLVERMKL_CPARDISO, MATSOLVERPASTIX.
%    MATSOLVERMATLAB, MATSOLVERPETSC, MATSOLVERBAS, MATSOLVERCUSPARSE
%
% Other: PETSC_NULL_STRING

%#codegen -args {coder.typeof(char(0),[1,inf])}
coder.cinclude('petsc4m.h');

if isempty(coder.target)
    error('Function petscGetObject must be compiled.');
end

if isequal(name, 'PETSC_NULL_STRING')
    [str, toplevel] = get_string('const char *', 'NULL', nargout>1);
elseif isequal(name,  'MATSAME')
    [str, toplevel] = get_string('MatType', 'MATSAME', nargout>1);
elseif isequal(name,  'MATMAIJ')
    [str, toplevel] = get_string('MatType', 'MATMAIJ', nargout>1);
elseif isequal(name,  'MATSEQMAIJ')
    [str, toplevel] = get_string('MatType', 'MATSEQMAIJ', nargout>1);
elseif isequal(name,  'MATMPIMAIJ')
    [str, toplevel] = get_string('MatType', 'MATMPIMAIJ', nargout>1);
elseif isequal(name,  'MATIS')
    [str, toplevel] = get_string('MatType', 'MATIS', nargout>1);
elseif isequal(name,  'MATAIJ')
    [str, toplevel] = get_string('MatType', 'MATAIJ', nargout>1);
elseif isequal(name,  'MATSEQAIJ')
    [str, toplevel] = get_string('MatType', 'MATSEQAIJ', nargout>1);
elseif isequal(name,  'MATMPIAIJ')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJ', nargout>1);
elseif isequal(name,  'MATAIJCRL')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJ', nargout>1);
elseif isequal(name,  'MATSEQAIJCRL')
    [str, toplevel] = get_string('MatType', 'MATSEQAIJCRL', nargout>1);
elseif isequal(name,  'MATMPIAIJCRL')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJCRL', nargout>1);
elseif isequal(name,  'MATAIJCUSPARSE')
    [str, toplevel] = get_string('MatType', 'MATAIJCUSPARSE', nargout>1);
elseif isequal(name,  'MATSEQAIJCUSPARSE')
    [str, toplevel] = get_string('MatType', 'MATSEQAIJCUSPARSE', nargout>1);
elseif isequal(name,  'MATMPIAIJCUSPARSE')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJCUSPARSE', nargout>1);
elseif isequal(name,  'MATAIJVIENNACL')
    [str, toplevel] = get_string('MatType', 'MATAIJVIENNACL', nargout>1);
elseif isequal(name,  'MATSEQAIJVIENNACL')
    [str, toplevel] = get_string('MatType', 'MATSEQAIJVIENNACL', nargout>1);
elseif isequal(name,  'MATMPIAIJVIENNACL')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJVIENNACL', nargout>1);
elseif isequal(name,  'MATAIJPERM')
    [str, toplevel] = get_string('MatType', 'MATAIJPERM', nargout>1);
elseif isequal(name,  'MATSEQAIJPERM')
    [str, toplevel] = get_string('MatType', 'MATSEQAIJPERM', nargout>1);
elseif isequal(name,  'MATMPIAIJPERM')
    [str, toplevel] = get_string('MatType', 'MATMPIAIJPERM', nargout>1);
elseif isequal(name,  'MATSHELL')
    [str, toplevel] = get_string('MatType', 'MATSHELL', nargout>1);
elseif isequal(name,  'MATDENSE')
    [str, toplevel] = get_string('MatType', 'MATDENSE', nargout>1);
elseif isequal(name,  'MATSEQDENSE')
    [str, toplevel] = get_string('MatType', 'MATSEQDENSE', nargout>1);
elseif isequal(name,  'MATMPIDENSE')
    [str, toplevel] = get_string('MatType', 'MATMPIDENSE', nargout>1);
elseif isequal(name,  'MATELEMENTAL')
    [str, toplevel] = get_string('MatType', 'MATELEMENTAL', nargout>1);
elseif isequal(name,  'MATBAIJ')
    [str, toplevel] = get_string('MatType', 'MATBAIJ', nargout>1);
elseif isequal(name,  'MATSEQBAIJ')
    [str, toplevel] = get_string('MatType', 'MATSEQBAIJ', nargout>1);
elseif isequal(name,  'MATMPIBAIJ')
    [str, toplevel] = get_string('MatType', 'MATMPIBAIJ', nargout>1);
elseif isequal(name,  'MATMPIADJ')
    [str, toplevel] = get_string('MatType', 'MATMPIADJ', nargout>1);
elseif isequal(name,  'MATSBAIJ')
    [str, toplevel] = get_string('MatType', 'MATSBAIJ', nargout>1);
elseif isequal(name,  'MATSEQSBAIJ')
    [str, toplevel] = get_string('MatType', 'MATSEQSBAIJ', nargout>1);
elseif isequal(name,  'MATMPISBAIJ')
    [str, toplevel] = get_string('MatType', 'MATMPISBAIJ', nargout>1);
elseif isequal(name,  'MATDAAD')
    [str, toplevel] = get_string('MatType', 'MATDAAD', nargout>1);
elseif isequal(name,  'MATMFFD')
    [str, toplevel] = get_string('MatType', 'MATMFFD', nargout>1);
elseif isequal(name,  'MATNORMAL')
    [str, toplevel] = get_string('MatType', 'MATNORMAL', nargout>1);
elseif isequal(name,  'MATNORMALHERMITIAN')
    [str, toplevel] = get_string('MatType', 'MATNORMALHERMITIAN', nargout>1);
elseif isequal(name,  'MATLRC')
    [str, toplevel] = get_string('MatType', 'MATLRC', nargout>1);
elseif isequal(name,  'MATSCATTER')
    [str, toplevel] = get_string('MatType', 'MATSCATTER', nargout>1);
elseif isequal(name,  'MATBLOCKMAT')
    [str, toplevel] = get_string('MatType', 'MATBLOCKMAT', nargout>1);
elseif isequal(name,  'MATCOMPOSITE')
    [str, toplevel] = get_string('MatType', 'MATCOMPOSITE', nargout>1);
elseif isequal(name,  'MATFFT')
    [str, toplevel] = get_string('MatType', 'MATFFT', nargout>1);
elseif isequal(name,  'MATFFTW')
    [str, toplevel] = get_string('MatType', 'MATFFTW', nargout>1);
elseif isequal(name,  'MATSEQCUFFT')
    [str, toplevel] = get_string('MatType', 'MATSEQCUFFT', nargout>1);
elseif isequal(name,  'MATTRANSPOSEMAT')
    [str, toplevel] = get_string('MatType', 'MATTRANSPOSEMAT', nargout>1);
elseif isequal(name,  'MATSCHURCOMPLEMENT')
    [str, toplevel] = get_string('MatType', 'MATSCHURCOMPLEMENT', nargout>1);
elseif isequal(name,  'MATPYTHON')
    [str, toplevel] = get_string('MatType', 'MATPYTHON', nargout>1);
elseif isequal(name,  'MATHYPRESTRUCT')
    [str, toplevel] = get_string('MatType', 'MATHYPRESTRUCT', nargout>1);
elseif isequal(name,  'MATHYPRESSTRUCT')
    [str, toplevel] = get_string('MatType', 'MATHYPRESSTRUCT', nargout>1);
elseif isequal(name,  'MATSUBMATRIX')
    [str, toplevel] = get_string('MatType', 'MATSUBMATRIX', nargout>1);
elseif isequal(name,  'MATLOCALREF')
    [str, toplevel] = get_string('MatType', 'MATSUBMATRIX', nargout>1);
elseif isequal(name,  'MATNEST')
    [str, toplevel] = get_string('MatType', 'MATNEST', nargout>1);
elseif isequal(name,  'MATPREALLOCATOR')
    [str, toplevel] = get_string('MatType', 'MATPREALLOCATOR', nargout>1);
elseif isequal(name,  'VECSEQ')
    [str, toplevel] = get_string('VecType', 'VECSEQ', nargout>1);
elseif isequal(name,  'VECMPI')
    [str, toplevel] = get_string('VecType', 'VECMPI', nargout>1);
elseif isequal(name,  'VECSTANDARD')
    [str, toplevel] = get_string('VecType', 'VECSTANDARD', nargout>1);
elseif isequal(name,  'VECSHARED')
    [str, toplevel] = get_string('VecType', 'VECSHARED', nargout>1);
elseif isequal(name,  'VECSEQVIENNACL')
    [str, toplevel] = get_string('VecType', 'VECSEQVIENNACL', nargout>1);
elseif isequal(name,  'VECMPIVIENNACL')
    [str, toplevel] = get_string('VecType', 'VECMPIVIENNACL', nargout>1);
elseif isequal(name,  'VECVIENNACL')
    [str, toplevel] = get_string('VecType', 'VECVIENNACL', nargout>1);
elseif isequal(name,  'VECSEQCUDA')
    [str, toplevel] = get_string('VecType', 'VECSEQCUDA', nargout>1);
elseif isequal(name,  'VECMPICUDA')
    [str, toplevel] = get_string('VecType', 'VECMPICUDA', nargout>1);
elseif isequal(name,  'VECCUDA')
    [str, toplevel] = get_string('VecType', 'VECCUDA', nargout>1);
elseif isequal(name,  'VECNEST')
    [str, toplevel] = get_string('VecType', 'VECNEST', nargout>1);
elseif isequal(name,  'KSPRICHARDSON')
    [str, toplevel] = get_string('KSPType', 'KSPRICHARDSON', nargout>1);
elseif isequal(name,  'KSPCHEBYSHEV')
    [str, toplevel] = get_string('KSPType', 'KSPCHEBYSHEV', nargout>1);
elseif isequal(name,  'KSPCG')
    [str, toplevel] = get_string('KSPType', 'KSPCG', nargout>1);
elseif isequal(name,  'KSPGROPPCG')
    [str, toplevel] = get_string('KSPType', 'KSPGROPPCG', nargout>1);
elseif isequal(name,  'KSPPIPECG')
    [str, toplevel] = get_string('KSPType', 'KSPPIPECG', nargout>1);
elseif isequal(name,  'KSPPIPECGRR')
    [str, toplevel] = get_string('KSPType', 'KSPPIPECGRR', nargout>1);
elseif isequal(name,  'KSPCGNE')
    [str, toplevel] = get_string('KSPType', 'KSPCGNE', nargout>1);
elseif isequal(name,  'KSPFCG')
    [str, toplevel] = get_string('KSPType', 'KSPFCG', nargout>1);
elseif isequal(name,  'KSPPIPEFCG')
    [str, toplevel] = get_string('KSPType', 'KSPPIPEFCG', nargout>1);
elseif isequal(name,  'KSPGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPGMRES', nargout>1);
elseif isequal(name,  'KSPPIPEFGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPPIPEFGMRES', nargout>1);
elseif isequal(name,  'KSPFGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPFGMRES', nargout>1);
elseif isequal(name,  'KSPLGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPLGMRES', nargout>1);
elseif isequal(name,  'KSPDGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPDGMRES', nargout>1);
elseif isequal(name,  'KSPPGMRES')
    [str, toplevel] = get_string('KSPType', 'KSPPGMRES', nargout>1);
elseif isequal(name,  'KSPTCQMR')
    [str, toplevel] = get_string('KSPType', 'KSPTCQMR', nargout>1);
elseif isequal(name,  'KSPBCGS')
    [str, toplevel] = get_string('KSPType', 'KSPBCGS', nargout>1);
elseif isequal(name,  'KSPIBCGS')
    [str, toplevel] = get_string('KSPType', 'KSPIBCGS', nargout>1);
elseif isequal(name,  'KSPFBCGS')
    [str, toplevel] = get_string('KSPType', 'KSPFBCGS', nargout>1);
elseif isequal(name,  'KSPFBCGSR')
    [str, toplevel] = get_string('KSPType', 'KSPFBCGSR', nargout>1);
elseif isequal(name,  'KSPBCGSL')
    [str, toplevel] = get_string('KSPType', 'KSPBCGSL', nargout>1);
elseif isequal(name,  'KSPCGS')
    [str, toplevel] = get_string('KSPType', 'KSPCGS', nargout>1);
elseif isequal(name,  'KSPTFQMR')
    [str, toplevel] = get_string('KSPType', 'KSPTFQMR', nargout>1);
elseif isequal(name,  'KSPCR')
    [str, toplevel] = get_string('KSPType', 'KSPCR', nargout>1);
elseif isequal(name,  'KSPPIPECR')
    [str, toplevel] = get_string('KSPType', 'KSPPIPECR', nargout>1);
elseif isequal(name,  'KSPLSQR')
    [str, toplevel] = get_string('KSPType', 'KSPLSQR', nargout>1);
elseif isequal(name,  'KSPPREONLY')
    [str, toplevel] = get_string('KSPType', 'KSPPREONLY', nargout>1);
elseif isequal(name,  'KSPQCG')
    [str, toplevel] = get_string('KSPType', 'KSPQCG', nargout>1);
elseif isequal(name,  'KSPBICG')
    [str, toplevel] = get_string('KSPType', 'KSPBICG', nargout>1);
elseif isequal(name,  'KSPMINRES')
    [str, toplevel] = get_string('KSPType', 'KSPMINRES', nargout>1);
elseif isequal(name,  'KSPSYMMLQ')
    [str, toplevel] = get_string('KSPType', 'KSPSYMMLQ', nargout>1);
elseif isequal(name,  'KSPLCD')
    [str, toplevel] = get_string('KSPType', 'KSPLCD', nargout>1);
elseif isequal(name,  'KSPPYTHON')
    [str, toplevel] = get_string('KSPType', 'KSPPYTHON', nargout>1);
elseif isequal(name,  'KSPGCR')
    [str, toplevel] = get_string('KSPType', 'KSPGCR', nargout>1);
elseif isequal(name,  'KSPPIPEGCR')
    [str, toplevel] = get_string('KSPType', 'KSPPIPEGCR', nargout>1);
elseif isequal(name,  'KSPTSIRM')
    [str, toplevel] = get_string('KSPType', 'KSPTSIRM', nargout>1);
elseif isequal(name,  'KSPCGLS')
    [str, toplevel] = get_string('KSPType', 'KSPCGLS', nargout>1);
elseif isequal(name,  'PCNONE')
    [str, toplevel] = get_string('PCType', 'PCNONE', nargout>1);
elseif isequal(name,  'PCJACOBI')
    [str, toplevel] = get_string('PCType', 'PCJACOBI', nargout>1);
elseif isequal(name,  'PCSOR')
    [str, toplevel] = get_string('PCType', 'PCSOR', nargout>1);
elseif isequal(name,  'PCLU')
    [str, toplevel] = get_string('PCType', 'PCLU', nargout>1);
elseif isequal(name,  'PCSHELL')
    [str, toplevel] = get_string('PCType', 'PCSHELL', nargout>1);
elseif isequal(name,  'PCBJACOBI')
    [str, toplevel] = get_string('PCType', 'PCBJACOBI', nargout>1);
elseif isequal(name,  'PCMG')
    [str, toplevel] = get_string('PCType', 'PCMG', nargout>1);
elseif isequal(name,  'PCEISENSTAT')
    [str, toplevel] = get_string('PCType', 'PCEISENSTAT', nargout>1);
elseif isequal(name,  'PCILU')
    [str, toplevel] = get_string('PCType', 'PCILU', nargout>1);
elseif isequal(name,  'PCICC')
    [str, toplevel] = get_string('PCType', 'PCICC', nargout>1);
elseif isequal(name,  'PCASM')
    [str, toplevel] = get_string('PCType', 'PCASM', nargout>1);
elseif isequal(name,  'PCGASM')
    [str, toplevel] = get_string('PCType', 'PCGASM', nargout>1);
elseif isequal(name,  'PCKSP')
    [str, toplevel] = get_string('PCType', 'PCKSP', nargout>1);
elseif isequal(name,  'PCCOMPOSITE')
    [str, toplevel] = get_string('PCType', 'PCCOMPOSITE', nargout>1);
elseif isequal(name,  'PCREDUNDANT')
    [str, toplevel] = get_string('PCType', 'PCREDUNDANT', nargout>1);
elseif isequal(name,  'PCSPAI')
    [str, toplevel] = get_string('PCType', 'PCSPAI', nargout>1);
elseif isequal(name,  'PCNN')
    [str, toplevel] = get_string('PCType', 'PCNN', nargout>1);
elseif isequal(name,  'PCCHOLESKY')
    [str, toplevel] = get_string('PCType', 'PCCHOLESKY', nargout>1);
elseif isequal(name,  'PCPBJACOBI')
    [str, toplevel] = get_string('PCType', 'PCPBJACOBI', nargout>1);
elseif isequal(name,  'PCMAT')
    [str, toplevel] = get_string('PCType', 'PCMAT', nargout>1);
elseif isequal(name,  'PCHYPRE')
    [str, toplevel] = get_string('PCType', 'PCHYPRE', nargout>1);
elseif isequal(name,  'PCPARMS')
    [str, toplevel] = get_string('PCType', 'PCPARMS', nargout>1);
elseif isequal(name,  'PCFIELDSPLIT')
    [str, toplevel] = get_string('PCType', 'PCFIELDSPLIT', nargout>1);
elseif isequal(name,  'PCTFS')
    [str, toplevel] = get_string('PCType', 'PCTFS', nargout>1);
elseif isequal(name,  'PCML')
    [str, toplevel] = get_string('PCType', 'PCML', nargout>1);
elseif isequal(name,  'PCGALERKIN')
    [str, toplevel] = get_string('PCType', 'PCGALERKIN', nargout>1);
elseif isequal(name,  'PCEXOTIC')
    [str, toplevel] = get_string('PCType', 'PCEXOTIC', nargout>1);
elseif isequal(name,  'PCCP')
    [str, toplevel] = get_string('PCType', 'PCCP', nargout>1);
elseif isequal(name,  'PCBFBT')
    [str, toplevel] = get_string('PCType', 'PCBFBT', nargout>1);
elseif isequal(name,  'PCLSC')
    [str, toplevel] = get_string('PCType', 'PCLSC', nargout>1);
elseif isequal(name,  'PCPYTHON')
    [str, toplevel] = get_string('PCType', 'PCPYTHON', nargout>1);
elseif isequal(name,  'PCPFMG')
    [str, toplevel] = get_string('PCType', 'PCPFMG', nargout>1);
elseif isequal(name,  'PCSYSPFMG')
    [str, toplevel] = get_string('PCType', 'PCSYSPFMG', nargout>1);
elseif isequal(name,  'PCREDISTRIBUTE')
    [str, toplevel] = get_string('PCType', 'PCREDISTRIBUTE', nargout>1);
elseif isequal(name,  'PCSVD')
    [str, toplevel] = get_string('PCType', 'PCSVD', nargout>1);
elseif isequal(name,  'PCGAMG')
    [str, toplevel] = get_string('PCType', 'PCGAMG', nargout>1);
elseif isequal(name,  'PCBDDC')
    [str, toplevel] = get_string('PCType', 'PCBDDC', nargout>1);
elseif isequal(name,  'PCKACZMARZ')
    [str, toplevel] = get_string('PCType', 'PCKACZMARZ', nargout>1);
elseif isequal(name,  'PCTELESCOPE')
    [str, toplevel] = get_string('PCType', 'PCTELESCOPE', nargout>1);
elseif isequal(name,  'MATSOLVERSUPERLU')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERSUPERLU', nargout>1);
elseif isequal(name,  'MATSOLVERSUPERLU_DIST')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERSUPERLU_DIST', nargout>1);
elseif isequal(name,  'MATSOLVERUMFPACK')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERUMFPACK', nargout>1);
elseif isequal(name,  'MATSOLVERCHOLMOD')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERCHOLMOD', nargout>1);
elseif isequal(name,  'MATSOLVERKLU')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERKLU', nargout>1);
elseif isequal(name,  'MATSOLVERELEMENTAL')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERELEMENTAL', nargout>1);
elseif isequal(name,  'MATSOLVERESSL')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERESSL', nargout>1);
elseif isequal(name,  'MATSOLVERLUSOL')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERLUSOL', nargout>1);
elseif isequal(name,  'MATSOLVERMUMPS')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERMUMPS', nargout>1);
elseif isequal(name,  'MATSOLVERMKL_PARDISO')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERMKL_PARDISO', nargout>1);
elseif isequal(name,  'MATSOLVERMKL_CPARDISO')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERMKL_CPARDISO', nargout>1);
elseif isequal(name,  'MATSOLVERPASTIX')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERPASTIX', nargout>1);
elseif isequal(name,  'MATSOLVERMATLAB')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERMATLAB', nargout>1);
elseif isequal(name,  'MATSOLVERPETSC')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERPETSC', nargout>1);
elseif isequal(name,  'MATSOLVERBAS')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERBAS', nargout>1);
elseif isequal(name,  'MATSOLVERCUSPARSE')
    [str, toplevel] = get_string('const MatSolverType', 'MATSOLVERCUSPARSE', nargout>1);
else
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
