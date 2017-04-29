% petsc4m depends on paracoder. Need to load it first
if ~exist('load_m2c.m', 'file')
    if exist('../paracoder/load_m2c.m', 'file')
        run('../paracoder/load_m2c.m')
    else
        error('Petsc4m depends on paracoder. Please install paracoder properly.')
    end
elseif ~exist('m2c.m', 'file')
    load_m2c
end

% Load the Petsc4m module
addpath(petscroot); %#ok<*MCAP>
addpath([petscroot '/Mat']);
addpath([petscroot '/Vec']);
addpath([petscroot '/KSP']);
addpath([petscroot '/PC']);
addpath([petscroot '/CRS']);

addpath([petscroot '/util'])
addpath([petscroot '/sys'])
addpath([petscroot '/exe'])
