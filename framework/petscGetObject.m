function obj = petscGetObject(name)
%petscGetObject Obtain an opaque object in PETSC
%
%    obj = petscGetObject(name)
%
%The supported names include:
%
% Others:  PETSC_IGNORE, PETSC_COMM_SELF, PETSC_COMM_WORLD

%#codegen -args {coder.typeof(char(0),[1,inf])}

if coder.target('MATLAB')
    error('Function petscGetObject must be compiled.');
end

%% InsertMode
if isequal(name, 'PETSC_IGNORE')
    obj = opaque_obj('void *', coder.opaque('void *',  'PETSC_IGNORE'));
elseif isequal(name, 'PETSC_COMM_SELF')
    obj = opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'PETSC_COMM_SELF'));
elseif isequal(name, 'PETSC_COMM_WORLD')
    obj = opaque_obj('MPI_Comm', coder.opaque('MPI_Comm',  'PETSC_COMM_WORLD'));
else
    m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
    obj = opaque_obj('void *', coder.opaque('void *',  'NULL'));
end

end
