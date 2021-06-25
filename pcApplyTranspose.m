function y = pcApplyTranspose(pc, x)
% pcApplyTranspose Computes y=M^-T x
%
%   y = pcApplyTranspose(pc, x)
%
% Input Arguments:
%   pc: The preconditioner object
%   x:  The input vector
%
% Output Argument:
%   y:  The output vecor
%
% SEE ALSO: pcCreate, pcApply, pcDestroy

xVec = petscVecCreateFromArray(PetscScalar(x));
yVec = petscVecDuplicate(xVec);

errCode = petscPCApplyTranspose(pc, xVec, yVec); assert(~errCode, 'petscPCApplyTranspose failed');

y = petscVecToArray(yVec);

petscVecDestroy(xVec);
petscVecDestroy(yVec);

end
