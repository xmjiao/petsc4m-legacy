function y = gamgApply(pc, x)
% gamgApply Computes y=M^-1 x
%
%   y = gamgApply(pc, x)
%
% Input Arguments:
%   pc: The preconditioner object
%   x:  The input vector
%
% Output Argument:
%   y:  The output vecor
%
% SEE ALSO: gamgCreate, gamgApplyTranspose, gamgDestroy

%#codegen -args {PetscPC, coder.typeof(PetscScalar(0), [inf, 1])}

xVec = petscVecCreateFromArray(PetscScalar(x));
yVec = petscVecDuplicate(xVec);

errCode = petscPCApply(pc, xVec, yVec); assert(~errCode, 'petscPCApply failed');

y = petscVecToArray(yVec);
petscVecDestroy(xVec);
petscVecDestroy(yVec);

end
