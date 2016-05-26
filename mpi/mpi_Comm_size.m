function [size, info, toplevel] = mpi_Comm_size(comm)
%mpi_Comm_size   Determines size of group associated with communicator
%
%  [size, info] =  mpi_Comm_size (comm)
%
%  comm Opaque MPI_Comm object.
%  size (int) number of processes in the group of comm
%
%  info (int) return code
%
%  SEE ALSO: mpi_Comm_rank
%
%  MPI_COMM_NULL is not considered a valid argument to this function
%
%
% C interface:
% int mpi_Comm_size(MPI_Comm comm, int *size ) 
% http://mpi.deino.net/mpi_functions/MPI_Comm_size.html

%#codegen -args {MPI_Comm}

size = int32(1); info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Comm_size', MPI_Comm(comm), coder.wref(size));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_size failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! [size,info] = mpi_Comm_size(comm);
%! assert(size == 1);
%! [rank,info] = mpi_Comm_rank(comm);
%! assert(rank == 0);
