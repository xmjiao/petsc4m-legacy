function [mat, errCode, topleve] = petscMatCreateSeqAIJ_FixedRows(m, n, nz)
[mat, errCode, topleve] = petscMatCreateSeqAIJ(m, n, nz);
