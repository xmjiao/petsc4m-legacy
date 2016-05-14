function [str, errCode, toplevel] = petscPCGetOptionsPrefix(pc)
%Gets the prefix used for searching for all PC options in the database.
%   errCode = petscPCGetOptionsPrefix(pc, in_str)
%
%   pc    - the PC context
%   in_str - the prefix string to prepend to all PC option requests
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscPCGetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  PCGetOptionsPrefix(PC pc,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCGetOptionsPrefix.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    % null-terminate the string.
    str0 = coder.opaque('const char *');    
    errCode = coder.ceval('PCGetOptionsPrefix', t_pc, coder.wref(str0));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCGetOptionsPrefix returned error code %d\n', errCode)
    end

    n = int32(0); %#ok<NASGU>
    n = coder.ceval('strlen', str0);
    str1 = zeros(1, n, 'uint8');
    coder.ceval('memcpy', coder.ref(str1), str0, n);
    
    str = char(str1);
end
end
