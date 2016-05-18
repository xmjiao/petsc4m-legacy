function info = mpi_Abort(comm, errorcode)
%mpi_Abort   Terminates MPI execution environment
%
%  info = mpi_Abort (comm, errcode)
%
%  comm Opaque MPI_Comm object.
%  errcode(int)	error code to return to invoking environment
%		split into 3 sections:
%		lower 8 bits: error class
%		next 9 bits: function enumeration (over  300  MPI functions)
%		upper 15 bits: error code (POSIX return value for the program)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Init, mpi_Finalize
%
% C interface:
% int MPI_Abort(MPI_Comm comm, int errorcode)
% http://mpi.deino.net/mpi_functions/MPI_Abort.html

%#codegen -args {MPI_Comm, int32(0)}

info = int32(0);
if coder.ismatlabthread
    m2c_error('MMPI:MPI_Abort', 'MPI_Abort was called');
else
    info = coder.ceval('MPI_Abort', MPI_Comm(comm), int32(errorcode));
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! try info = mpi_Abort(MPI_COMM_WORLD, int32(100));
%! catch; end
