function val = petscGetEnum(name)
%petscGetEnum Obtain an enumerate value in PETSC
%
%    val = petscGetEnum(name)
%
%The supported names include:
% InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, 
%      INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES
%
% MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY
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
% VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, 
%      VEC_SUBSET_OFF_PROC_ENTRIES
%
% Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT

%#codegen -args {coder.typeof(char(0),[1,inf])}

if coder.target('MATLAB')
    return;
end

val = int32(intmin);

%% InsertMode
if isequal(name, 'NOT_SET_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'NOT_SET_VALUES'));
elseif isequal(name, 'INSERT_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'INSERT_VALUES'));
elseif isequal(name, 'ADD_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'ADD_VALUES'));
elseif isequal(name, 'MAX_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'MAX_VALUES'));
elseif isequal(name, 'INSERT_ALL_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'INSERT_ALL_VALUES'));
elseif isequal(name, 'ADD_ALL_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'ADD_ALL_VALUES'));
elseif isequal(name, 'INSERT_BC_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'INSERT_BC_VALUES'));
elseif isequal(name, 'ADD_BC_VALUES')
    val = coder.ceval(' ', coder.opaque('InsertMode', 'ADD_BC_VALUES'));
elseif isequal(name, 'MAT_FINAL_ASSEMBLY')
    val = coder.ceval(' ', coder.opaque('MatAssemblyType', 'MAT_FINAL_ASSEMBLY'));
elseif isequal(name, 'MAT_FLUSH_ASSEMBLY')
    val = coder.ceval(' ', coder.opaque('MatAssemblyType', 'MAT_FLUSH_ASSEMBLY'));
elseif isequal(name, 'MAT_ROW_ORIENTED')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_ROW_ORIENTED'));
elseif isequal(name, 'MAT_SYMMETRIC')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_SYMMETRIC'));
elseif isequal(name, 'MAT_STRUCTURALLY_SYMMETRIC')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_STRUCTURALLY_SYMMETRIC'));
elseif isequal(name, 'MAT_NEW_DIAGONALS')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_NEW_DIAGONALS'));
elseif isequal(name, 'MAT_IGNORE_OFF_PROC_ENTRIES')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_IGNORE_OFF_PROC_ENTRIES'));
elseif isequal(name, 'MAT_USE_HASH_TABLE')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_USE_HASH_TABLE'));
elseif isequal(name, 'MAT_KEEP_NONZERO_PATTERN')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_KEEP_NONZERO_PATTERN'));
elseif isequal(name, 'MAT_IGNORE_ZERO_ENTRIES')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_IGNORE_ZERO_ENTRIES'));
elseif isequal(name, 'MAT_USE_INODES')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_USE_INODES'));
elseif isequal(name, 'MAT_HERMITIAN')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_HERMITIAN'));
elseif isequal(name, 'MAT_SYMMETRY_ETERNAL')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_SYMMETRY_ETERNAL'));
elseif isequal(name, 'MAT_NEW_NONZERO_LOCATION_ERR')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_NEW_NONZERO_LOCATION_ERR'));
elseif isequal(name, 'MAT_IGNORE_LOWER_TRIANGULAR')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_IGNORE_LOWER_TRIANGULAR'));
elseif isequal(name, 'MAT_ERROR_LOWER_TRIANGULAR')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_ERROR_LOWER_TRIANGULAR'));
elseif isequal(name, 'MAT_GETROW_UPPERTRIANGULAR')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_GETROW_UPPERTRIANGULAR'));
elseif isequal(name, 'MAT_SPD')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_SPD'));
elseif isequal(name, 'MAT_NO_OFF_PROC_ZERO_ROWS')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_NO_OFF_PROC_ZERO_ROWS'));
elseif isequal(name, 'MAT_NO_OFF_PROC_ENTRIES')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_NO_OFF_PROC_ENTRIES'));
elseif isequal(name, 'MAT_NEW_NONZERO_ALLOCATION_ERR')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_NEW_NONZERO_ALLOCATION_ERR'));
elseif isequal(name, 'MAT_SUBSET_OFF_PROC_ENTRIES')
    val = coder.ceval(' ', coder.opaque('MatOption', 'MAT_SUBSET_OFF_PROC_ENTRIES'));
elseif isequal(name, 'PETSC_DETERMINE')
    val = coder.ceval(' ', coder.opaque('PetscInt', 'PETSC_DETERMINE'));
elseif isequal(name, 'PETSC_DECIDE')
    val = coder.ceval(' ', coder.opaque('PetscInt', 'PETSC_DECIDE'));
elseif isequal(name, 'PETSC_DEFAULT')
    val = coder.ceval(' ', coder.opaque('PetscInt', 'PETSC_DEFAULT'));
else
    m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
end

end
