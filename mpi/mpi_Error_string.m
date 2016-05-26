function [msg, info, toplevel] = mpi_Error_string(errcode)
%Returns a string for a given error code.
%
% [msg, info] = mpi_Error_string(errcode)
%
% C interface:
%     int MPI_Error_string(int errorcode, char *string, int *resultlen)
% http://mpi.deino.net/mpi_functions/MPI_Error_string.html

%#codegen -args {int32(0)}

coder.inline('always');

msg0 = zeros(1, 1024, 'uint8');

ptr = coder.opaque('char *'); %#ok<NASGU>
ptr = coder.ceval('(char *)', coder.ref(msg0));

info = int32(0); %#ok<NASGU>
resultlen = int32(0);
info = coder.ceval('MPI_Error_string', errcode, ptr, coder.ref(resultlen));
msg = char(msg0(1:resultlen));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Error_string with error code %d\n', info);
end
