function [errCode, toplevel] = petscMatMPIAIJSetPreallocationCSR_Indexonly(mat, ix, jx)
[errCode, toplevel] = petscMatMPIAIJSetPreallocationCSR(mat, ix, jx);
