function comm = MPI_Comm(arg) %#codegen
%MPI_Comm Maps from an opaque object to MPI_Comm
%  comm = MPI_Comm(arg)

coder.inline('always');

if nargin==0 && isempty(coder.target)
    comm = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm')
    m2c_error('MPI_Comm:WrongType', ...
        'Incorrect data type %s. Expected MPI_Comm.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    comm = arg;
else
    comm = castdata('MPI_Comm', arg.data);
end
