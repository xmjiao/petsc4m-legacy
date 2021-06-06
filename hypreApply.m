function y = hypreApply(pc, x)
% hypreApply Computes y=M^-1 x
%
%   y = hypreApply(pc, x)
%
% Input Arguments:
%   pc: The preconditioner object
%   x:  The input vector
%
% Output Argument:
%   y:  The output vecor
%
% SEE ALSO: hypreCreate, hypreApplyTranspose, hypreDestroy

xVec = petscVecCreateFromArray(x);
yVec = petscVecDuplicate(xVec);

errCode = petscPCApply(pc, xVec, yVec); assert(~errCode, 'petscPCApply failed');

y = petscVecToArray(yVec);

petscVecDestroy(xVec);
petscVecDestroy(yVec);

end
