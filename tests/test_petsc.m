function test_petsc
% test script for petsc4m

if isoctave
    test_hdl = @test;
else
    test_hdl = @mtest;
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
    [n, nmax] = test_hdl(file);
    if n<nmax
        error('FAILED %d out of %d tests\n', nmax-n, nmax)
    else
        fprintf(1, 'PASSED %d out of %d tests\n', n, nmax);
    end
end

end
