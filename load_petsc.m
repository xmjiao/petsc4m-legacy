function load_petsc(varargin)

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

% Set petscroot explicitly to bypass a bug in Octave 4.2.1
petscroot = which('load_petsc');
petscroot = petscroot(1:end-13);
if petscroot == '.'
    petscroot=pwd;
end
if ispc
    petscroot = strrep(petscroot,'\','/');
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

if isoctave || ~usejava('jvm') || nargin>0
    init_petsc(varargin{:})
end

% Show help message
if ~exist(['petscInitialized.' mexext], 'file')
    disp('Please run build_petsc to compile Petsc4m.');
end
