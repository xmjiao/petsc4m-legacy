function secs = mpi_Wtime
%mpi_Wtime    Returns an elapsed time on the calling processor
%
%  secs = mpi_Wtime
%
%  secs (double) Time in seconds since an arbitrary time in the past
%
%  SEE ALSO: mpi_Wtick
%
% C interface:
% double MPI_Wtime(void)
% http://mpi.deino.net/mpi_functions/MPI_Wtime.html

%#codegen -args {}
coder.cinclude('mpetsc.h');

secs = 0; %#ok<NASGU>
secs = coder.ceval('MPI_Wtime');
