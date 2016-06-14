function errCode = mptOptionsInsert(opts)
%Inserts options into the PETSc optoins database from a string
%   errCode = mptOptionsInsert(opts)
%
%   opts - string that contains options separated by blanks
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: sys/petscOptionsInsertFile, sys/petscOptionsSetValue,
%   sys/petscOptionsSetInt, sys/petscOptionsGetReal,
%   sys/petscOptionsHasName, sys/petscOptionsGetInt,
%   sys/petscOptionsSetReal, sys/petscOptionsGetBool,
%   sys/petscOptionsGetString

%This function is codegen compatbile, but no need to a top-level function
if ~isempty(opts) && opts(end)~=char(0)
    opts = [opts char(0)];
end

% Insert into options database and enforce error checking
[errCode,~] = petscOptionsInsertString(opts);
end
