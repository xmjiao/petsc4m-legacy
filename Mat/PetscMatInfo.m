function [info, nfields] = PetscMatInfo %codegen
% MATLAB structure corresponding to MatInfo in Petsc

coder.inline('always');
coder.cinclude('petsc4m.h');

info = struct('block_size', 0, ...        % block size
    'nz_allocated',0, 'nz_used', 0, 'nz_unneeded', 0, ...   % number of nonzeros
    'memory', 0, ...                      % memory allocated
  	'assemblies', 0, ...                  % number of matrix assemblies called
    'mallocs', 0, ...                     % number of mallocs during MatSetValues()
    'fill_ratio_given', 0, 'fill_ratio_needed', 0, ...      % fill ratio for LU/ILU
    'factor_mallocs', 0 ...               % number of mallocs during factorization */
);

coder.cstructname(info, 'PetscMatInfo');

if nargout>1
    nfields = int32(length(fieldnames(info)));
end
end
