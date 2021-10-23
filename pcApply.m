function y = pcApply(pc, x)
% pcApply Computes y=M^-1 x
%
%   y = pcApply(pc, x)
%
% Input Arguments:
%   pc: The preconditioner object
%   x:  The input vector
%
% Output Argument:
%   y:  The output vecor
%
% SEE ALSO: pcCreate, pcApplyTranspose, pcDestroy

%#codegen -args {PetscPC, coder.typeof(PetscScalar(0), [inf, 1])}

xVec = petscVecCreateFromArray(PetscScalar(x));
yVec = petscVecDuplicate(xVec);

% errCode = petscPCApply(pc, xVec, yVec); assert(~errCode, 'petscPCApply failed');


y = petscVecToArray(yVec);
petscVecDestroy(xVec);
petscVecDestroy(yVec);

end
