function pc = hypreDestroy(pc)
% hypreDestroy Destroy the context of a hypre preconditioner
%
%   pc = hypreCreate(pc)
%
% Input Argument:
%   pc: PETSc preconditoiner object
%
% Output Argument:
%   pc: Destroyed PC object
%
%  SEE ALSO: hypreCreate, hypreApply, hypreApplyTranspose

[mat, ~, errCode] = petscPCGetOperators(pc); assert(errCode==int(0), 'petscPCGetOperators failed');

[~, errCode] = petscMatDestroy(mat); assert(errCode==int(0), 'petscMatDestroy failed');

[pc, errCode] = petscPCDestroy(pc); assert(errCode==int(0), 'petscPCDestroy failed');

end
