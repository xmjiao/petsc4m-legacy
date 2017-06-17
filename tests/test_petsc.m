function test_petsc
% test script for petsc4m

if isoctave
  mtest = @test;
end

% Test vectors, matrices, and KSP solvers
lines = [grep_pattern([petscroot '/Vec/petscVec*.m'], '%\!test'), ...
    grep_pattern([petscroot '/Mat/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/KSP/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/CRS/petsc*.m'], '%\!test'), ...
    grep_pattern([petscroot '/petsc*.m'], '%\!test')];

files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s:\n', file(length(petscroot)+2:end));
    [n, nmax] = mtest(file);
    if n<nmax
        error('FAILED %d out of %d tests\n', nmax-n, nmax)
        break
    else
        fprintf(1, 'PASSED %d out of %d tests\n', n, nmax);
    end
end

end
