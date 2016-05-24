function comm = MPI_Comm(varargin) %#codegen
%Map an opaque object into an MPI_Comm object
%
%  MPI_Comm() simply returns a definition of the m2c_opaque_type,
%  suitable in the argument specification for codegen.
%
%  MPI_Comm(obj) or MPI_Comm(obj, false) converts obj into an MPI_Comm object.
%
%  MPI_Comm(obj, true) wraps the obj into an opaque object. This should be
%  used if the opaque object needs to be returned to MATLAB.

coder.inline('always');

comm = m2c_opaque_obj('MPI_Comm', varargin{:});
