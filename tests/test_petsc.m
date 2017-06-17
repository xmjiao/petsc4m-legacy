function test_petsc
% test script for petsc4m


% Test vectors, matrices, and KSP solvers
lines = [grep_pattern([petscroot '/Vec/petscVec*.m'], '%\!test'), ...
    grep_pattern([petscroot '/Mat/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/KSP/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/CRS/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/petsc*.m'], '%\!test')];

files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s: ', file(length(petscroot)+2:end));
    mtest(file);
end

end
