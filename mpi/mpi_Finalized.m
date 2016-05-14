function [flag, info, toplevel] = mpi_Finalized
%mpi_Finalized     Indicates whether MPI_Finalize has been called.
%
%  [flag, info] = mpi_Finalized
%
%  flag(int) 0 false
%	         1 true
%
%  info(int) return code
%
%  SEE ALSO: mpi_Init, mpi_Finalize, mpi_Initialized
%
% C interface:
% int MPI_Finalized(int *flag )
% http://mpi.deino.net/mpi_functions/MPI_Finalized.html

%#codegen -args {}

coder.cinclude('mpi.h');

flag = int32(0); info = int32(0); %#ok<NASGU>
info = coder.ceval('MPI_Finalized', coder.wref(flag));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Finalized returned error code %d\n', info)
end
