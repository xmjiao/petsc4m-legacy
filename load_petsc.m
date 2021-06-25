function load_petsc(varargin)

persistent loaded;

% Load only once
if ~isempty(loaded)
  return
elseif isoctave
    % Prevent Octave from loading it twice
    loaded = true;
end

% petsc4m depends on paracoder. Need to load it first
if ~exist('load_m2c.m', 'file')
    if exist('../paracoder/startup.m', 'file')
        run('../paracoder/startup.m')
    else
        error('Petsc4m depends on paracoder. Please install paracoder properly.')
    end
elseif ~exist('m2c.m', 'file')
    load_m2c
end

% Set petscroot explicitly to bypass a bug in Octave 4.2.1
petscroot = fileparts(which('load_petsc'));
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

[~,dir] = fileparts(petscroot);

switch dir % Load type definitions
case 'spetsc4m'
    addpath([petscroot '/sys/spetsc'])
case 'cpetsc4m'
    addpath([petscroot '/sys/cpetsc'])
case 'zpetsc4m'
    addpath([petscroot '/sys/zpetsc'])
otherwise
    addpath([petscroot '/sys/dpetsc'])
end

if isoctave || ~usejava('jvm')
    % PETSc should not be initialized automatically in MATLAB
    % if JAVA is enabled
    init_petsc
end

% Show help message
if ~exist(['petscInitialized.' mexext], 'file')
    disp('Please run build_petsc to compile Petsc4m.');
end

loaded = true;
