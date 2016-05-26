function [info, toplevel] = mpi_Finalize
%mpi_Finalize  Terminates MPI execution environment
%
%  info =  mpi_Finalize
%
%  info(int) return code
%
%  SEE ALSO: mpi_Init, mpi_Initialized, mpi_Finalized
%
%  Note: This is a system/driver level function. A user function in general 
%  should not call this function. It is called automatically at exit
%  by MATLAB/Octave if the MMPI module was initialized.
%
% C interface:
% int MPI_Finalize(void )
% http://mpi.deino.net/mpi_functions/MPI_Finalize.html

%#codegen -args {}

info = int32(0);

if ~mpi_Finalized
    info = coder.ceval('MPI_Finalize');
end

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Finalize failed with error message %s\n', mpi_Error_string(info))
end
