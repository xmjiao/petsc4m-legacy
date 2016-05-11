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
% Other:
%     PETSC_IGNORE

%#codegen -args {coder.typeof(char(0),[1,inf])}

if coder.target('MATLAB')
    error('Function petscGetObject must be compiled.');
end

%% InsertMode
if isequal(name, 'PETSC_IGNORE')
    if nargout>1
        obj = opaque_obj('void *', coder.opaque('void *',  'PETSC_IGNORE'));
        toplevel = true;
    else
        obj = coder.opaque('void *',  'PETSC_IGNORE');
    end
elseif isequal(name, 'PETSC_COMM_SELF')
    if nargout>1
        obj = opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'PETSC_COMM_SELF'));
        toplevel = true;
    else
        obj = coder.opaque('MPI_Comm',  'PETSC_COMM_SELF');
    end
elseif isequal(name, 'PETSC_COMM_WORLD')
    if nargout>1
        obj = opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'PETSC_COMM_WORLD'));
        toplevel = true;
    else
        obj = coder.opaque('MPI_Comm',  'PETSC_COMM_WORLD');
    end
elseif isequal(name, 'MATSAME')
    if nargout>1
        obj = opaque_obj('const char *', coder.opaque('const char *',  'MATSAME'));
        toplevel = true;
    else
        obj = coder.opaque('const char *',  'MATSAME');
    end
else
    m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
    if nargout>1
        obj = opaque_obj('void *', coder.opaque('void *',  'NULL'));
        toplevel = true;
    else
        obj = coder.opaque('void *',  'NULL');
    end
end

end
