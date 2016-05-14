function [info, toplevel] = mpi_Init(varargin)
%mpi_Init  Initialize the MPI execution environment
%
%  info = mpi_Init
%  info = mpi_Init(argc, argv)
%
%  argc and argv are opaque pointers pointing to int and char **, respectively.
%
%  info(int) return code
%
%  Note: This is a system/driver level function. A user function in general 
%  should not call this function. It is called automatically at startup
%  by MATLAB/Octave when the mpi module is initialized. 
%
%  SEE ALSO: mpi_Finalize, mpi_Initialized, mpi_Finalized
%
% C interface:
%   int MPI_Init(int *argc, char ***argv )
% http://mpi.deino.net/mpi_functions/MPI_Init.html

%#codegen -args {}

coder.cinclude('mpi.h');

info = int32(0); %#ok<NASGU>

if nargin==2
    argc = varargin{1};
    argv = varargin{2};
else
    assert(nargin==0);
    
    argc = coder.opaque('int *', 'NULL');
    argv = coder.opaque('char ***', 'NULL');
end

info = coder.ceval('MPI_Init', argc, argv);

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Init returned error code %d\n', info)
end
