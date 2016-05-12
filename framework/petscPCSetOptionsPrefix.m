function [errCode, toplevel] = petscPCSetOptionsPrefix(pc, in_str)
%Sets the prefix used for searching for all PC options in the database. 
%   errCode = petscPCSetOptionsPrefix(pc, in_str)
%
%   pc    - the PC context
%   in_str - the prefix string to prepend to all PC option requests
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscPCSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  PCSetOptionsPrefix(PC pc,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetOptionsPrefix.html

%#codegen -args {PetscPC, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    % null-terminate the string.
    str0 = [in_str char(0)];
    
    errCode = coder.ceval('PCSetOptionsPrefix', t_pc, coder.rref(str0));

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
