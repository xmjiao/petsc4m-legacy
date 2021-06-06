function y = hypreApplyTranspose(pc, x)
% hypreApplyTranspose Computes y=M^-T x
%
%   y = hypreApplyTranspose(pc, x)
%
% Input Arguments:
%   pc: The preconditioner object
%   x:  The input vector
%
% Output Argument:
%   y:  The output vecor
%
% SEE ALSO: hypreCreate, hypreApply, hypreDestroy

xVec = petscVecCreateFromArray(x);
yVec = petscVecDuplicate(xVec);

errCode = petscPCApplyTranspose(pc, xVec, yVec); assert(~errCode, 'petscPCApplyTranspose failed');

y = petscVecToArray(yVec);

petscVecDestroy(xVec);
petscVecDestroy(yVec);

end
