function root = petscroot
% PETSCROOT  Determine root directory of petsc4m

persistent root__;

if isempty(root__)
    root__ = fileparts(which('petscroot.m'));
end

root = root__;
