function pc = gamgDestroy(pc)
% gamgDestroy Destroy the context of a gamg preconditioner
%
%   pc = gamgCreate(pc)
%
% Input Argument:
%   pc: PETSc preconditoiner object
%
% Output Argument:
%   pc: Destroyed PC object
%
%  SEE ALSO: gamgCreate, gamgApply, gamgApplyTranspose

[mat, ~, errCode] = petscPCGetOperators(pc); assert(errCode==int32(0), 'petscPCGetOperators failed');

[~, errCode] = petscMatDestroy(mat); assert(errCode==int32(0), 'petscMatDestroy failed');

[pc, errCode] = petscPCDestroy(pc); assert(errCode==int32(0), 'petscPCDestroy failed');

end
