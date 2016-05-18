function [obj, toplevel] = petscGetObject(name)
%petscGetObject Obtain an opaque object in PETSC
%
%    obj = petscGetObject(name)
%
%The supported names include:
%
% MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD
%
% Other:
%     PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC,
%     PETSC_NULL_INT, PETSC_NULL_REAL

%#codegen -args {coder.typeof(char(0),[1,inf])}

if coder.target('MATLAB')
    error('Function petscGetObject must be compiled.');
end

switch name
    case 'PETSC_COMM_SELF'
        [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_SELF', nargout>1);
    case 'PETSC_COMM_WORLD'
        [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_WORLD', nargout>1);
    case 'PETSC_IGNORE'
        [obj, toplevel] = get_obj('void *', 'PETSC_IGNORE', nargout>1);
    case 'PETSC_NULL_OPTIONS'
        [obj, toplevel] = get_obj('PetscOptions', 'NULL', nargout>1);
    case 'PETSC_NULL_MAT'
        [obj, toplevel] = get_obj('Mat', 'NULL', nargout>1);
    case 'PETSC_NULL_VEC'
        [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1);
    case 'PETSC_NULL_INT'
        [obj, toplevel] = get_obj('int *', 'NULL', nargout>1);
    case 'PETSC_NULL_REAL'
        [obj, toplevel] = get_obj('double *', 'NULL', nargout>1);
    otherwise
        m2c_error('petscGetNum:UnknownConstant', 'Unknonw constant %s.', [name char(0)]);
        if nargout>1
            obj = m2c_opaque_obj('void *', coder.opaque('void *',  'NULL'));
            toplevel = true;
        end
end
end

function [obj, toplevel] = get_obj(type, name, toplevel)
coder.inline('always')
if toplevel
    obj = m2c_opaque_obj(type, coder.opaque(type,  name));
else
    obj = coder.opaque(type,  name);
end
end
