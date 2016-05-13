% This script is called automatically when MATLAB and Octave exists.

addpath(pwd); %#ok<*MCAP>
addpath([pwd '/framework']);

if ~exist('m2c', 'file')
    run ../M2C/startup
end

build

if ismac && ~usejava('jvm')
    petscInitialize;
else
    warning('PETSc cannot be used when Java is enabled.');
end
