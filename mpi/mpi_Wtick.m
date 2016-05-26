function res = mpi_Wtick
%mpi_Wtick    Returns the resolution of MPI_Wtime
%
%  res = mpi_Wtick
%
%  res  (double) Time in seconds of resolution of mpi_Wtime
%
%  SEE ALSO: mpi_Wtime
%
% C interface:
% double mpi_Wtick(void )
% http://www.mcs.anl.gov/research/projects/mpi/www/www3/mpi_Wtick.html

%#codegen -args {}

res = 0; %#ok<NASGU>
res = coder.ceval('MPI_Wtick');
