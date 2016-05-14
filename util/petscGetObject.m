function [obj, toplevel] = petscGetObject(name)
%petscGetObject Obtain an opaque object in PETSC
%
%    obj = petscGetObject(name)
%
%The supported names include:
%
% MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD
%
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
% KSPType: KSPRICHARDSON, KSPCHEBYSHEV, KSPCG, KSPGROPPCG,
%     KSPPIPECG, KSPPIPECGRR, KSPCGNE, KSPNASH,
%     KSPSTCG, KSPGLTR, KSPFCG, KSPPIPEFCG, KSPGMRES,
%     KSPPIPEFGMRES, KSPFGMRES, KSPLGMRES, KSPDGMRES,
%     KSPPGMRES, KSPTCQMR, KSPBCGS, KSPIBCGS, KSPFBCGS,
%     KSPFBCGSR, KSPBCGSL, KSPCGS, KSPTFQMR, KSPCR, KSPPIPECR,
%     KSPLSQR, KSPPREONLY, KSPQCG, KSPBICG, KSPMINRES, KSPSYMMLQ,
%     KSPLCD, KSPPYTHON, KSPGCR, KSPPIPEGCR, KSPTSIRM, KSPCGLS
%
% PCType: PCNONE, PCJACOBI, PCSOR, PCLU, PCSHELL, PCBJACOBI, PCMG,
%     PCEISENSTAT, PCILU, PCICC, PCASM, PCGASM, PCKSP, PCCOMPOSITE,
%     PCREDUNDANT, PCSPAI, PCNN, PCCHOLESKY, PCPBJACOBI, PCMAT, PCHYPRE,
%     PCPARMS, PCFIELDSPLIT, PCTFS, PCML, PCGALERKIN, PCEXOTIC, PCCP,
%     PCBFBT, PCLSC, PCPYTHON, PCPFMG, PCSYSPFMG, PCREDISTRIBUTE, PCSVD,
%     PCGAMG, PCSACUSP, PCSACUSPPOLY, PCBICGSTABCUSP, PCAINVCUSP,
%     PCBDDC, PCKACZMARZ, PCTELESCOPE
%
% Other:
%     PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC

%#codegen -args {coder.typeof(char(0),[1,inf])}

if coder.target('MATLAB')
    error('Function petscGetObject must be compiled.');
end

switch name
    case 'PETSC_IGNORE'
        [obj, toplevel] = get_obj('void *', 'PETSC_IGNORE', nargout>1);
    case 'PETSC_COMM_SELF'
        [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_SELF', nargout>1);
    case 'PETSC_COMM_WORLD'
        [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_WORLD', nargout>1);
    case 'MATSAME'
        [obj, toplevel] = get_obj('MatType', 'MATSAME', nargout>1);
    case 'MATMAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATMAIJ', nargout>1);
    case 'MATSEQMAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATSEQMAIJ', nargout>1);
    case 'MATMPIMAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATMPIMAIJ', nargout>1);
    case 'MATIS'
        [obj, toplevel] = get_obj('MatType', 'MATIS', nargout>1);
    case 'MATAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATAIJ', nargout>1);
    case 'MATSEQAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJ', nargout>1);
    case 'MATMPIAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJ', nargout>1);
    case 'MATAIJCRL'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJ', nargout>1);
    case 'MATSEQAIJCRL'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJCRL', nargout>1);
    case 'MATMPIAIJCRL'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJCRL', nargout>1);
    case 'MATAIJCUSP'
        [obj, toplevel] = get_obj('MatType', 'MATAIJCUSP', nargout>1);
    case 'MATSEQAIJCUSP'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJCUSP', nargout>1);
    case 'MATMPIAIJCUSP'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJCUSP', nargout>1);
    case 'MATAIJCUSPARSE'
        [obj, toplevel] = get_obj('MatType', 'MATAIJCUSPARSE', nargout>1);
    case 'MATSEQAIJCUSPARSE'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJCUSPARSE', nargout>1);
    case 'MATMPIAIJCUSPARSE'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJCUSPARSE', nargout>1);
    case 'MATAIJVIENNACL'
        [obj, toplevel] = get_obj('MatType', 'MATAIJVIENNACL', nargout>1);
    case 'MATSEQAIJVIENNACL'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJVIENNACL', nargout>1);
    case 'MATMPIAIJVIENNACL'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJVIENNACL', nargout>1);
    case 'MATAIJPERM'
        [obj, toplevel] = get_obj('MatType', 'MATAIJPERM', nargout>1);
    case 'MATSEQAIJPERM'
        [obj, toplevel] = get_obj('MatType', 'MATSEQAIJPERM', nargout>1);
    case 'MATMPIAIJPERM'
        [obj, toplevel] = get_obj('MatType', 'MATMPIAIJPERM', nargout>1);
    case 'MATSHELL'
        [obj, toplevel] = get_obj('MatType', 'MATSHELL', nargout>1);
    case 'MATDENSE'
        [obj, toplevel] = get_obj('MatType', 'MATDENSE', nargout>1);
    case 'MATSEQDENSE'
        [obj, toplevel] = get_obj('MatType', 'MATSEQDENSE', nargout>1);
    case 'MATMPIDENSE'
        [obj, toplevel] = get_obj('MatType', 'MATMPIDENSE', nargout>1);
    case 'MATELEMENTAL'
        [obj, toplevel] = get_obj('MatType', 'MATELEMENTAL', nargout>1);
    case 'MATBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATBAIJ', nargout>1);
    case 'MATSEQBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATSEQBAIJ', nargout>1);
    case 'MATMPIBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATMPIBAIJ', nargout>1);
    case 'MATMPIADJ'
        [obj, toplevel] = get_obj('MatType', 'MATMPIADJ', nargout>1);
    case 'MATSBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATSBAIJ', nargout>1);
    case 'MATSEQSBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATSEQSBAIJ', nargout>1);
    case 'MATMPISBAIJ'
        [obj, toplevel] = get_obj('MatType', 'MATMPISBAIJ', nargout>1);
    case 'MATSEQBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATSEQBSTRM', nargout>1);
    case 'MATMPIBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATMPIBSTRM', nargout>1);
    case 'MATBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATBSTRM', nargout>1);
    case 'MATSEQSBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATSEQSBSTRM', nargout>1);
    case 'MATMPISBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATMPISBSTRM', nargout>1);
    case 'MATSBSTRM'
        [obj, toplevel] = get_obj('MatType', 'MATSBSTRM', nargout>1);
    case 'MATDAAD'
        [obj, toplevel] = get_obj('MatType', 'MATDAAD', nargout>1);
    case 'MATMFFD'
        [obj, toplevel] = get_obj('MatType', 'MATMFFD', nargout>1);
    case 'MATNORMAL'
        [obj, toplevel] = get_obj('MatType', 'MATNORMAL', nargout>1);
    case 'MATNORMALHERMITIAN'
        [obj, toplevel] = get_obj('MatType', 'MATNORMALHERMITIAN', nargout>1);
    case 'MATLRC'
        [obj, toplevel] = get_obj('MatType', 'MATLRC', nargout>1);
    case 'MATSCATTER'
        [obj, toplevel] = get_obj('MatType', 'MATSCATTER', nargout>1);
    case 'MATBLOCKMAT'
        [obj, toplevel] = get_obj('MatType', 'MATBLOCKMAT', nargout>1);
    case 'MATCOMPOSITE'
        [obj, toplevel] = get_obj('MatType', 'MATCOMPOSITE', nargout>1);
    case 'MATFFT'
        [obj, toplevel] = get_obj('MatType', 'MATFFT', nargout>1);
    case 'MATFFTW'
        [obj, toplevel] = get_obj('MatType', 'MATFFTW', nargout>1);
    case 'MATSEQCUFFT'
        [obj, toplevel] = get_obj('MatType', 'MATSEQCUFFT', nargout>1);
    case 'MATTRANSPOSEMAT'
        [obj, toplevel] = get_obj('MatType', 'MATTRANSPOSEMAT', nargout>1);
    case 'MATSCHURCOMPLEMENT'
        [obj, toplevel] = get_obj('MatType', 'MATSCHURCOMPLEMENT', nargout>1);
    case 'MATPYTHON'
        [obj, toplevel] = get_obj('MatType', 'MATPYTHON', nargout>1);
    case 'MATHYPRESTRUCT'
        [obj, toplevel] = get_obj('MatType', 'MATHYPRESTRUCT', nargout>1);
    case 'MATHYPRESSTRUCT'
        [obj, toplevel] = get_obj('MatType', 'MATHYPRESSTRUCT', nargout>1);
    case 'MATSUBMATRIX'
        [obj, toplevel] = get_obj('MatType', 'MATSUBMATRIX', nargout>1);
    case 'MATLOCALREF'
        [obj, toplevel] = get_obj('MatType', 'MATSUBMATRIX', nargout>1);
    case 'MATNEST'
        [obj, toplevel] = get_obj('MatType', 'MATNEST', nargout>1);
    case 'MATPREALLOCATOR'
        [obj, toplevel] = get_obj('MatType', 'MATPREALLOCATOR', nargout>1);
    case 'KSPRICHARDSON'
        [obj, toplevel] = get_obj('KSPType', 'KSPRICHARDSON', nargout>1);
    case 'KSPCHEBYSHEV'
        [obj, toplevel] = get_obj('KSPType', 'KSPCHEBYSHEV', nargout>1);
    case 'KSPCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPCG', nargout>1);
    case 'KSPGROPPCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPGROPPCG', nargout>1);
    case 'KSPPIPECG'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPECG', nargout>1);
    case 'KSPPIPECGRR'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPECGRR', nargout>1);
    case 'KSPCGNE'
        [obj, toplevel] = get_obj('KSPType', 'KSPCGNE', nargout>1);
    case 'KSPNASH'
        [obj, toplevel] = get_obj('KSPType', 'KSPNASH', nargout>1);
    case 'KSPSTCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPSTCG', nargout>1);
    case 'KSPGLTR'
        [obj, toplevel] = get_obj('KSPType', 'KSPGLTR', nargout>1);
    case 'KSPFCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPFCG', nargout>1);
    case 'KSPPIPEFCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPEFCG', nargout>1);
    case 'KSPGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPGMRES', nargout>1);
    case 'KSPPIPEFGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPEFGMRES', nargout>1);
    case 'KSPFGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPFGMRES', nargout>1);
    case 'KSPLGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPLGMRES', nargout>1);
    case 'KSPDGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPDGMRES', nargout>1);
    case 'KSPPGMRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPPGMRES', nargout>1);
    case 'KSPTCQMR'
        [obj, toplevel] = get_obj('KSPType', 'KSPTCQMR', nargout>1);
    case 'KSPBCGS'
        [obj, toplevel] = get_obj('KSPType', 'KSPBCGS', nargout>1);
    case 'KSPIBCGS'
        [obj, toplevel] = get_obj('KSPType', 'KSPIBCGS', nargout>1);
    case 'KSPFBCGS'
        [obj, toplevel] = get_obj('KSPType', 'KSPFBCGS', nargout>1);
    case 'KSPFBCGSR'
        [obj, toplevel] = get_obj('KSPType', 'KSPFBCGSR', nargout>1);
    case 'KSPBCGSL'
        [obj, toplevel] = get_obj('KSPType', 'KSPBCGSL', nargout>1);
    case 'KSPCGS'
        [obj, toplevel] = get_obj('KSPType', 'KSPCGS', nargout>1);
    case 'KSPTFQMR'
        [obj, toplevel] = get_obj('KSPType', 'KSPTFQMR', nargout>1);
    case 'KSPCR'
        [obj, toplevel] = get_obj('KSPType', 'KSPCR', nargout>1);
    case 'KSPPIPECR'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPECR', nargout>1);
    case 'KSPLSQR'
        [obj, toplevel] = get_obj('KSPType', 'KSPLSQR', nargout>1);
    case 'KSPPREONLY'
        [obj, toplevel] = get_obj('KSPType', 'KSPPREONLY', nargout>1);
    case 'KSPQCG'
        [obj, toplevel] = get_obj('KSPType', 'KSPQCG', nargout>1);
    case 'KSPBICG'
        [obj, toplevel] = get_obj('KSPType', 'KSPBICG', nargout>1);
    case 'KSPMINRES'
        [obj, toplevel] = get_obj('KSPType', 'KSPMINRES', nargout>1);
    case 'KSPSYMMLQ'
        [obj, toplevel] = get_obj('KSPType', 'KSPSYMMLQ', nargout>1);
    case 'KSPLCD'
        [obj, toplevel] = get_obj('KSPType', 'KSPLCD', nargout>1);
    case 'KSPPYTHON'
        [obj, toplevel] = get_obj('KSPType', 'KSPPYTHON', nargout>1);
    case 'KSPGCR'
        [obj, toplevel] = get_obj('KSPType', 'KSPGCR', nargout>1);
    case 'KSPPIPEGCR'
        [obj, toplevel] = get_obj('KSPType', 'KSPPIPEGCR', nargout>1);
    case 'KSPTSIRM'
        [obj, toplevel] = get_obj('KSPType', 'KSPTSIRM', nargout>1);
    case 'KSPCGLS'
        [obj, toplevel] = get_obj('KSPType', 'KSPCGLS', nargout>1);
    case 'PCNONE'
        [obj, toplevel] = get_obj('PCType', 'PCNONE', nargout>1);
    case 'PCJACOBI'
        [obj, toplevel] = get_obj('PCType', 'PCJACOBI', nargout>1);
    case 'PCSOR'
        [obj, toplevel] = get_obj('PCType', 'PCSOR', nargout>1);
    case 'PCLU'
        [obj, toplevel] = get_obj('PCType', 'PCLU', nargout>1);
    case 'PCSHELL'
        [obj, toplevel] = get_obj('PCType', 'PCSHELL', nargout>1);
    case 'PCBJACOBI'
        [obj, toplevel] = get_obj('PCType', 'PCBJACOBI', nargout>1);
    case 'PCMG'
        [obj, toplevel] = get_obj('PCType', 'PCMG', nargout>1);
    case 'PCEISENSTAT'
        [obj, toplevel] = get_obj('PCType', 'PCEISENSTAT', nargout>1);
    case 'PCILU'
        [obj, toplevel] = get_obj('PCType', 'PCILU', nargout>1);
    case 'PCICC'
        [obj, toplevel] = get_obj('PCType', 'PCICC', nargout>1);
    case 'PCASM'
        [obj, toplevel] = get_obj('PCType', 'PCASM', nargout>1);
    case 'PCGASM'
        [obj, toplevel] = get_obj('PCType', 'PCGASM', nargout>1);
    case 'PCKSP'
        [obj, toplevel] = get_obj('PCType', 'PCKSP', nargout>1);
    case 'PCCOMPOSITE'
        [obj, toplevel] = get_obj('PCType', 'PCCOMPOSITE', nargout>1);
    case 'PCREDUNDANT'
        [obj, toplevel] = get_obj('PCType', 'PCREDUNDANT', nargout>1);
    case 'PCSPAI'
        [obj, toplevel] = get_obj('PCType', 'PCSPAI', nargout>1);
    case 'PCNN'
        [obj, toplevel] = get_obj('PCType', 'PCNN', nargout>1);
    case 'PCCHOLESKY'
        [obj, toplevel] = get_obj('PCType', 'PCCHOLESKY', nargout>1);
    case 'PCPBJACOBI'
        [obj, toplevel] = get_obj('PCType', 'PCPBJACOBI', nargout>1);
    case 'PCMAT'
        [obj, toplevel] = get_obj('PCType', 'PCMAT', nargout>1);
    case 'PCHYPRE'
        [obj, toplevel] = get_obj('PCType', 'PCHYPRE', nargout>1);
    case 'PCPARMS'
        [obj, toplevel] = get_obj('PCType', 'PCPARMS', nargout>1);
    case 'PCFIELDSPLIT'
        [obj, toplevel] = get_obj('PCType', 'PCFIELDSPLIT', nargout>1);
    case 'PCTFS'
        [obj, toplevel] = get_obj('PCType', 'PCTFS', nargout>1);
    case 'PCML'
        [obj, toplevel] = get_obj('PCType', 'PCML', nargout>1);
    case 'PCGALERKIN'
        [obj, toplevel] = get_obj('PCType', 'PCGALERKIN', nargout>1);
    case 'PCEXOTIC'
        [obj, toplevel] = get_obj('PCType', 'PCEXOTIC', nargout>1);
    case 'PCCP'
        [obj, toplevel] = get_obj('PCType', 'PCCP', nargout>1);
    case 'PCBFBT'
        [obj, toplevel] = get_obj('PCType', 'PCBFBT', nargout>1);
    case 'PCLSC'
        [obj, toplevel] = get_obj('PCType', 'PCLSC', nargout>1);
    case 'PCPYTHON'
        [obj, toplevel] = get_obj('PCType', 'PCPYTHON', nargout>1);
    case 'PCPFMG'
        [obj, toplevel] = get_obj('PCType', 'PCPFMG', nargout>1);
    case 'PCSYSPFMG'
        [obj, toplevel] = get_obj('PCType', 'PCSYSPFMG', nargout>1);
    case 'PCREDISTRIBUTE'
        [obj, toplevel] = get_obj('PCType', 'PCREDISTRIBUTE', nargout>1);
    case 'PCSVD'
        [obj, toplevel] = get_obj('PCType', 'PCSVD', nargout>1);
    case 'PCGAMG'
        [obj, toplevel] = get_obj('PCType', 'PCGAMG', nargout>1);
    case 'PCSACUSP'
        [obj, toplevel] = get_obj('PCType', 'PCSACUSP', nargout>1);
    case 'PCSACUSPPOLY'
        [obj, toplevel] = get_obj('PCType', 'PCSACUSPPOLY', nargout>1);
    case 'PCBICGSTABCUSP'
        [obj, toplevel] = get_obj('PCType', 'PCBICGSTABCUSP', nargout>1);
    case 'PCAINVCUSP'
        [obj, toplevel] = get_obj('PCType', 'PCAINVCUSP', nargout>1);
    case 'PCBDDC'
        [obj, toplevel] = get_obj('PCType', 'PCBDDC', nargout>1);
    case 'PCKACZMARZ'
        [obj, toplevel] = get_obj('PCType', 'PCKACZMARZ', nargout>1);
    case 'PCTELESCOPE'
        [obj, toplevel] = get_obj('PCType', 'PCTELESCOPE', nargout>1);
    case 'PETSC_NULL_OPTIONS'
        [obj, toplevel] = get_obj('PetscOptions', 'NULL', nargout>1);
    case 'PETSC_NULL_MAT'
        [obj, toplevel] = get_obj('Mat', 'NULL', nargout>1);
    case 'PETSC_NULL_VEC'
        [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1);
    case 'PETSC_NULL_INT'
        [obj, toplevel] = get_obj('int *', 'NULL', nargout>1);
    case 'PETSC_NULL_REAL'
        [obj, toplevel] = get_obj('double *', 'NULL', nargout>1);
    case 'PETSC_NULL_STRING'
        [obj, toplevel] = get_obj('char *', 'NULL', nargout>1);
    otherwise
        m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
        if nargout>1
            obj = opaque_obj('void *', coder.opaque('void *',  'NULL'));
            toplevel = true;
        end
end
end

function [obj, toplevel] = get_obj(type, name, toplevel)
coder.inline('always')
if toplevel
    obj = opaque_obj(type, coder.opaque(type,  name));
else
    obj = coder.opaque(type,  name);
end
end
