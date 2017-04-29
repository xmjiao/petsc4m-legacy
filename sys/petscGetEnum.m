function [val, toplevel] = petscGetEnum(name)
%petscGetEnum Obtain an enumerate value in PETSC
%
%    val = petscGetEnum(name)
%
%The supported names include:
%
% PetscBool:  PETSC_TRUE, PETSC_FALSE
%
% VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES,
%      VEC_SUBSET_OFF_PROC_ENTRIES
%
% MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC,
%      MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES,
%      MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN,
%      MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN,
%      MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR,
%      MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR,
%      MAT_GETROW_UPPERTRIANGULAR, MAT_SPD,
%      MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES,
%      MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR,
%      MAT_SUBSET_OFF_PROC_ENTRIES
%
% MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN
%
% MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN
%
% MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX
%
% InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES,
%      INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES
%
% MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY
%
% MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM
%
% MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,
%      MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT
%
% NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2
%
% KSPNormType: KSP_NORM_DEFAULT, KSP_NORM_NONE, KSP_NORM_PRECONDITIONED,
%              KSP_NORM_UNPRECONDITIONED,KSP_NORM_NATURAL
%
% PCSide: PC_LEFT, PC_RIGHT, PC_SYMMETRIC
%
% Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT

%#codegen -args {coder.typeof(char(0),[1,inf])}

coder.cinclude('petsc4m.h');

if isempty(coder.target)
    error('Function petscGetEnum must be compiled.');
end

%% InsertMode
switch name
    case 'PETSC_TRUE'
        [val, toplevel] = get_val('PetscBool', 'PETSC_TRUE', nargin>1);
    case 'PETSC_FALSE'
        [val, toplevel] = get_val('PetscBool', 'PETSC_FALSE', nargin>1);
    case 'DIFFERENT_NONZERO_PATTERN'
        [val, toplevel] = get_val('MatStructure', 'DIFFERENT_NONZERO_PATTERN', nargin>1);
    case 'SUBSET_NONZERO_PATTERN'
        [val, toplevel] = get_val('MatStructure', 'SUBSET_NONZERO_PATTERN', nargin>1);
    case 'SAME_NONZERO_PATTERN'
        [val, toplevel] = get_val('MatStructure', 'SAME_NONZERO_PATTERN', nargin>1);
    case 'MAT_DO_NOT_COPY_VALUES'
        [val, toplevel] = get_val('MatDuplicateOption', 'MAT_DO_NOT_COPY_VALUES', nargin>1);
    case 'MAT_COPY_VALUES'
        [val, toplevel] = get_val('MatDuplicateOption', 'MAT_COPY_VALUES', nargin>1);
    case 'MAT_SHARE_NONZERO_PATTERN'
        [val, toplevel] = get_val('MatDuplicateOption', 'MAT_SHARE_NONZERO_PATTERN', nargin>1);
    case 'MAT_INITIAL_MATRIX'
        [val, toplevel] = get_val('MatReuse', 'MAT_INITIAL_MATRIX', nargin>1);
    case 'MAT_REUSE_MATRIX'
        [val, toplevel] = get_val('MatReuse', 'MAT_REUSE_MATRIX', nargin>1);
    case 'MAT_IGNORE_MATRIX'
        [val, toplevel] = get_val('MatReuse', 'MAT_IGNORE_MATRIX', nargin>1);
    case 'MAT_INPLACE_MATRIX'
        [val, toplevel] = get_val('MatReuse', 'MAT_INPLACE_MATRIX', nargin>1);
    case 'NOT_SET_VALUES'
        [val, toplevel] = get_val('InsertMode', 'NOT_SET_VALUES', nargin>1);
    case 'INSERT_VALUES'
        [val, toplevel] = get_val('InsertMode', 'INSERT_VALUES', nargin>1);
    case 'ADD_VALUES'
        [val, toplevel] = get_val('InsertMode', 'ADD_VALUES', nargin>1);
    case 'MAX_VALUES'
        [val, toplevel] = get_val('InsertMode', 'MAX_VALUES', nargin>1);
    case 'INSERT_ALL_VALUES'
        [val, toplevel] = get_val('InsertMode', 'INSERT_ALL_VALUES', nargin>1);
    case 'ADD_ALL_VALUES'
        [val, toplevel] = get_val('InsertMode', 'ADD_ALL_VALUES', nargin>1);
    case 'INSERT_BC_VALUES'
        [val, toplevel] = get_val('InsertMode', 'INSERT_BC_VALUES', nargin>1);
    case 'ADD_BC_VALUES'
        [val, toplevel] = get_val('InsertMode', 'ADD_BC_VALUES', nargin>1);
    case 'MAT_FINAL_ASSEMBLY'
        [val, toplevel] = get_val('MatAssemblyType', 'MAT_FINAL_ASSEMBLY', nargin>1);
    case 'MAT_FLUSH_ASSEMBLY'
        [val, toplevel] = get_val('MatAssemblyType', 'MAT_FLUSH_ASSEMBLY', nargin>1);
    case 'MAT_LOCAL'
        [val, toplevel] = get_val('MatInfoType', 'MAT_LOCAL', nargin>1);
    case 'MAT_GLOBAL_MAX'
        [val, toplevel] = get_val('MatInfoType', 'MAT_GLOBAL_MAX', nargin>1);
    case 'MAT_GLOBAL_SUM'
        [val, toplevel] = get_val('MatInfoType', 'MAT_GLOBAL_SUM', nargin>1);
    case 'MAT_ROW_ORIENTED'
        [val, toplevel] = get_val('MatOption', 'MAT_ROW_ORIENTED', nargin>1);
    case 'MAT_SYMMETRIC'
        [val, toplevel] = get_val('MatOption', 'MAT_SYMMETRIC', nargin>1);
    case 'MAT_STRUCTURALLY_SYMMETRIC'
        [val, toplevel] = get_val('MatOption', 'MAT_STRUCTURALLY_SYMMETRIC', nargin>1);
    case 'MAT_NEW_DIAGONALS'
        [val, toplevel] = get_val('MatOption', 'MAT_NEW_DIAGONALS', nargin>1);
    case 'MAT_IGNORE_OFF_PROC_ENTRIES'
        [val, toplevel] = get_val('MatOption', 'MAT_IGNORE_OFF_PROC_ENTRIES', nargin>1);
    case 'MAT_USE_HASH_TABLE'
        [val, toplevel] = get_val('MatOption', 'MAT_USE_HASH_TABLE', nargin>1);
    case 'MAT_KEEP_NONZERO_PATTERN'
        [val, toplevel] = get_val('MatOption', 'MAT_KEEP_NONZERO_PATTERN', nargin>1);
    case 'MAT_IGNORE_ZERO_ENTRIES'
        [val, toplevel] = get_val('MatOption', 'MAT_IGNORE_ZERO_ENTRIES', nargin>1);
    case 'MAT_USE_INODES'
        [val, toplevel] = get_val('MatOption', 'MAT_USE_INODES', nargin>1);
    case 'MAT_HERMITIAN'
        [val, toplevel] = get_val('MatOption', 'MAT_HERMITIAN', nargin>1);
    case 'MAT_SYMMETRY_ETERNAL'
        [val, toplevel] = get_val('MatOption', 'MAT_SYMMETRY_ETERNAL', nargin>1);
    case 'MAT_NEW_NONZERO_LOCATION_ERR'
        [val, toplevel] = get_val('MatOption', 'MAT_NEW_NONZERO_LOCATION_ERR', nargin>1);
    case 'MAT_IGNORE_LOWER_TRIANGULAR'
        [val, toplevel] = get_val('MatOption', 'MAT_IGNORE_LOWER_TRIANGULAR', nargin>1);
    case 'MAT_ERROR_LOWER_TRIANGULAR'
        [val, toplevel] = get_val('MatOption', 'MAT_ERROR_LOWER_TRIANGULAR', nargin>1);
    case 'MAT_GETROW_UPPERTRIANGULAR'
        [val, toplevel] = get_val('MatOption', 'MAT_GETROW_UPPERTRIANGULAR', nargin>1);
    case 'MAT_SPD'
        [val, toplevel] = get_val('MatOption', 'MAT_SPD', nargin>1);
    case 'MAT_NO_OFF_PROC_ZERO_ROWS'
        [val, toplevel] = get_val('MatOption', 'MAT_NO_OFF_PROC_ZERO_ROWS', nargin>1);
    case 'MAT_NO_OFF_PROC_ENTRIES'
        [val, toplevel] = get_val('MatOption', 'MAT_NO_OFF_PROC_ENTRIES', nargin>1);
    case 'MAT_NEW_NONZERO_ALLOCATION_ERR'
        [val, toplevel] = get_val('MatOption', 'MAT_NEW_NONZERO_ALLOCATION_ERR', nargin>1);
    case 'MAT_SUBSET_OFF_PROC_ENTRIES'
        [val, toplevel] = get_val('MatOption', 'MAT_SUBSET_OFF_PROC_ENTRIES', nargin>1);
    case 'MAT_FACTOR_NONE'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_NONE', nargin>1);
    case 'MAT_FACTOR_LU'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_LU', nargin>1);
    case 'MAT_FACTOR_CHOLESKY'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_CHOLESKY', nargin>1);
    case 'MAT_FACTOR_ILU'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_ILU', nargin>1);
    case 'MAT_FACTOR_ICC'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_ICC', nargin>1);
    case 'MAT_FACTOR_ILUDT'
        [val, toplevel] = get_val('MatFactorType', 'MAT_FACTOR_ILUDT', nargin>1);
    case 'NORM_1'
        [val, toplevel] = get_val('NormType', 'NORM_1', nargin>1);
    case 'NORM_2'
        [val, toplevel] = get_val('NormType', 'NORM_2', nargin>1);
    case 'NORM_FROBENIUS'
        [val, toplevel] = get_val('NormType', 'NORM_FROBENIUS', nargin>1);
    case 'NORM_INFINITY'
        [val, toplevel] = get_val('NormType', 'NORM_INFINITY', nargin>1);
    case 'NORM_1_AND_2'
        [val, toplevel] = get_val('NormType', 'NORM_1_AND_2', nargin>1);
    case 'KSP_NORM_DEFAULT'
        [val, toplevel] = get_val('KSPNormType', 'KSP_NORM_DEFAULT', nargin>1);
    case 'KSP_NORM_NONE'
        [val, toplevel] = get_val('KSPNormType', 'KSP_NORM_NONE', nargin>1);
    case 'KSP_NORM_PRECONDITIONED'
        [val, toplevel] = get_val('KSPNormType', 'KSP_NORM_PRECONDITIONED', nargin>1);
    case 'KSP_NORM_UNPRECONDITIONED'
        [val, toplevel] = get_val('KSPNormType', 'KSP_NORM_UNPRECONDITIONED', nargin>1);
    case 'KSP_NORM_NATURAL'
        [val, toplevel] = get_val('KSPNormType', 'KSP_NORM_NATURAL', nargin>1);
    case 'PC_LEFT'
        [val, toplevel] = get_val('PetscInt', 'PC_LEFT', nargin>1);
    case 'PC_RIGHT'
        [val, toplevel] = get_val('PetscInt', 'PC_RIGHT', nargin>1);
    case 'PC_SYMMETRIC'
        [val, toplevel] = get_val('PetscInt', 'PC_SYMMETRIC', nargin>1);
    case 'PETSC_DETERMINE'
        [val, toplevel] = get_val('PetscInt', 'PETSC_DETERMINE', nargin>1);
    case 'PETSC_DECIDE'
        [val, toplevel] = get_val('PetscInt', 'PETSC_DECIDE', nargin>1);
    case 'PETSC_DEFAULT'
        [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1);
    otherwise
        toplevel = nargout>1;
        val = int32(intmin);
        if toplevel
            m2c_error('petscGetEnum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
        end
end
end

function [val, toplevel] = get_val(type, name, toplevel)
coder.inline('always');

val = int32(intmin);             %#ok<NASGU>
val = coder.ceval(' ', coder.opaque(type, name));
end
