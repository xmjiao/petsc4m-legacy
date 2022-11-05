function [errCode, toplevel] = petscMatSeqAIJSetPreallocationCSR_Indexonly(mat, ix, jx)
[errCode, toplevel] = petscMatSeqAIJSetPreallocationCSR(mat, ix, jx);
