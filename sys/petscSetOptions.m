function errCode = petscSetOptions(in_str)
%Inserts options into the database from a string
%   errCode = petscSetOptions(in_str)
%
%   in_str -string that contains options separated by blanks 
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscAssembleMat, petscAssembleVec, petscSolve


errCode = petscOptionsInsertString(in_str);
end
