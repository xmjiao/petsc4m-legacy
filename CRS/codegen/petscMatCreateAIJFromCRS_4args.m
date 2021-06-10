function [mat, toplevel] = petscMatCreateAIJFromCRS_4args(row_ptr, col_ind, val, ncols)
[mat, toplevel] = petscMatCreateAIJFromCRS(row_ptr, col_ind, val, ncols);
