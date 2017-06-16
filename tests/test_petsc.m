function test_petsc
% test script for petsc4m

mtest petscVecToArray
mtest petscVecCreateFromArray

mtest petscMatAIJToCRS.m
mtest petscMatCreateAIJFromCRS

mtest petscSolveCRS
mtest petscSolve

end
