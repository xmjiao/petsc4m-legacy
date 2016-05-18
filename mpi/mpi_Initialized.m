function [flag, info, toplevel] = mpi_Initialized
%mpi_Initialized	Indicates whether mpi_Init has been called
%
%  [flag, info] = mpi_Initialized
%
%  flag(int) 0 false
%	         1 true
%
%  info(int) return code
%
%  SEE ALSO: mpi_Init, mpi_Finalize, mpi_Finalized
%
% C interface:
% int MPI_Initialized(int *flag )
% http://mpi.deino.net/mpi_functions/MPI_Initialized.html

%#codegen -args {}

coder.cinclude('mpi.h');

flag = int32(0); info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Initialized', coder.wref(flag));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Initialized returned error code %d\n', info)
end
