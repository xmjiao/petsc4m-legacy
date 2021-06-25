function pc = pcDestroy(pc)
% pcDestroy Destroy the context of a pc preconditioner
%
%   pc = pcCreate(pc)
%
% Input Argument:
%   pc: PETSc preconditoiner object
%
% Output Argument:
%   pc: Destroyed PC object
%
%  SEE ALSO: pcCreate, pcApply, pcApplyTranspose

[mat, ~, errCode] = petscPCGetOperators(pc); assert(errCode==int32(0), 'petscPCGetOperators failed');

[~, errCode] = petscMatDestroy(mat); assert(errCode==int32(0), 'petscMatDestroy failed');

[pc, errCode] = petscPCDestroy(pc); assert(errCode==int32(0), 'petscPCDestroy failed');

end
