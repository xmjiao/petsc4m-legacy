function [errCode, toplevel] = petscPCSetOptionsPrefix(pc, prefix)
%Sets the prefix used for searching for all PC options in the database. 
%   errCode = petscPCSetOptionsPrefix(pc, prefix)
%
%   pc    - the PC context
%   prefix - the prefix string to prepend to all PC option requests.
%            It must be null-terminated.
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscPCSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  PCSetOptionsPrefix(PC pc,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetOptionsPrefix.html

%#codegen -args {PetscPC, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_pc = PetscPC(pc);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscPCSetOptionsPrefix:InputError', ...
            'The argument must be a null-terminated string.')
    end
    
    errCode = coder.ceval('PCSetOptionsPrefix', t_pc, coder.rref(prefix));

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
