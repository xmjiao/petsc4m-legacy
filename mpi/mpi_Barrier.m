function [info, toplevel] = mpi_Barrier(comm)
%mpi_Barrier   Blocks until all processes in the communicator have reached this routine.
%
%  info = mpi_Barrier (comm)
%
%  comm         Opaque MPI_Comm object.
%
%  info (int)	return code
%
%  SEE ALSO: mpi_Bcast, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  mpi_Barrier is a collective operation on comm (all ranks must call it)
%
% C interface:
%    int MPI_Barrier(MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Barrier.html

%#codegen -args {MPI_Comm}

info = int32(0); %#ok<NASGU>
info = coder.ceval('MPI_Barrier', MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Barrier failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! info = mpi_Barrier(MPI_COMM_WORLD);
%! assert(info==0);
