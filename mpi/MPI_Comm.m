function comm = MPI_Comm(arg, opaque) %#codegen
%Map an opaque object into a PETSc MPI_Comm object
%
%  comm = MPI_Comm() simply returns a definition of the
%  opaque_obj_type definition, suitable in the argument
%  specification for codegen.
%
%  comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg
%  into a PETSc Options object.
%
%  comm = MPI_Comm(arg, true) wraps the arg into an opaque object. 
%  This should be used if the object needs to be returned to
%  MATLAB. Note that the value of opaque must be determined at
%  compile time.
%
% See also PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    comm = opaque_obj_type; 
    return;
end

if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm')
    m2c_error('MPI_Comm:WrongType', ...
        'Incorrect data type %s. Expected MPI_Comm.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    if nargin==1 || ~opaque
        comm = arg;
    else
        comm = opaque_obj('MPI_Comm', arg);
    end
else
    comm = castdata('MPI_Comm', arg.data);
end

end