function [info, nfields] = PetscMatInfo %codegen
% MATLAB structure corresponding to MatInfo in Petsc

coder.inline('always');
coder.cinclude('petsc4m.h');

info = struct('block_size', double(0), ...        % block size
    'nz_allocated',double(0), ...
    'nz_used', double(0), ...
    'nz_unneeded', double(0), ...   % number of nonzeros
    'memory', double(0), ...                      % memory allocated
  	'assemblies', double(0), ...                  % number of matrix assemblies called
    'mallocs', double(0), ...                     % number of mallocs during MatSetValues()
    'fill_ratio_given', double(0), ...
    'fill_ratio_needed', double(0), ...      % fill ratio for LU/ILU
    'factor_mallocs', double(0) ...               % number of mallocs during factorization */
);

coder.cstructname(info, 'PetscMatInfo');

if nargout>1
    nfields = int32(length(fieldnames(info)));
end
end
