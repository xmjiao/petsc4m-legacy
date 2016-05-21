function [errCode, toplevel] = petscPCAppendOptionsPrefix(pc, prefix)
%Appends to the prefix used for searching for all PC options in the database. 
%
%   errCode = petscPCAppendOptionsPrefix(pc, prefix)
%
%   pc    - the PC context
%   prefix - the prefix string to prepend to all PC option requests.
%            It must be null-terminated.
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscPCSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  PCAppendOptionsPrefix(PC pc,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCAppendOptionsPrefix.html

%#codegen -args {PetscPC, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_pc = PetscPC(pc);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscPCAppendOptionsPrefix:InputError', ...
            'The 2nd argument must be a null-terminated string.')
    end
    
    errCode = coder.ceval('PCAppendOptionsPrefix', t_pc, coder.rref(prefix));

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCAppendOptionsPrefix returned error code %d\n', errCode)
    end
end

end
