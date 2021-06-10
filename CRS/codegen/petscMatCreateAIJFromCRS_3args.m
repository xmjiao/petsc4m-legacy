function [mat, toplevel] = petscMatCreateAIJFromCRS_3args(row_ptr, col_ind, val)
[mat, toplevel] = petscMatCreateAIJFromCRS(row_ptr, col_ind, val);
