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

% [mat, ~, errCode] = petscPCGetOperators(pc); assert(errCode==int32(0), 'petscPCGetOperators failed');
% 
% [~, errCode] = petscMatDestroy(mat); assert(errCode==int32(0), 'petscMatDestroy failed');
% 
% [pc, errCode] = petscPCDestroy(pc); assert(errCode==int32(0), 'petscPCDestroy failed');

ksp = pc;
[mat, ~, errCode] = petscKSPGetOperators(ksp); assert(errCode==int32(0), 'petscPCGetOperators failed');
[~, errCode] = petscMatDestroy(mat); assert(errCode==int32(0), 'petscMatDestroy failed');
pc  = petscKSPCleanup(ksp);

end
