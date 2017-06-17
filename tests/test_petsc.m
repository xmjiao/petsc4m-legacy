function test_petsc
% test script for petsc4m

% Test vectors
mtest petscVecToArray
mtest petscVecCreateFromArray
mtest petscVecAXPY
mtest petscVecAYPX

% Test matrices
mtest petscMatAIJToCRS.m
mtest petscMatCreateAIJFromCRS

% Test solvers
mtest petscSolveCRS
mtest petscSolve

end
