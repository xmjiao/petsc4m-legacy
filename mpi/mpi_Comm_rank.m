function [rank, info, toplevel] = mpi_Comm_rank(comm)
%mpi_Comm_rank  Determines the rank of the calling process in the communicator
%
%  [rank, info] =  mpi_Comm_rank (comm)
%
%  comm       Opaque MPI_Comm object.
%  rank (int) rank of the calling process in group of comm
%
%  info (int) return code
%
%  SEE ALSO: mpi_Comm_size
%
% C interface:
% int mpi_Comm_rank(MPI_Comm comm, int *rank ) 
% http://mpi.deino.net/mpi_functions/MPI_Comm_rank.html

%#codegen -args {MPI_Comm}

info = int32(0); %#ok<NASGU>
rank = int32(0);

info = coder.ceval('MPI_Comm_rank', MPI_Comm(comm), coder.wref(rank));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_rank failed with error message %s\n', mpi_Error_string(info))
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
