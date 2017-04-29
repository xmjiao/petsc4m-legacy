function [errCode, toplevel] = petscKSPAppendOptionsPrefix(ksp, prefix)
%Appends to the prefix used for searching for all KSP options in the database. 
%
%   errCode = petscKSPAppendOptionsPrefix(ksp, prefix)
%
%   ksp    - the KSP context
%   prefix - the prefix string to prepend to all KSP option requests
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscKSPSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  KSPAppendOptionsPrefix(KSP ksp,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPAppendOptionsPrefix.html

%#codegen -args {PetscKSP, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('Petsc4m:petscKSPAppendOptionsPrefix:InputError', ...
            'The 2nd argument must be a null-terminated string.')
    end
    
    errCode = coder.ceval('KSPAppendOptionsPrefix', t_ksp, coder.rref(prefix));

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPAppendOptionsPrefix returned error code %d\n', errCode)
    end
end

end
