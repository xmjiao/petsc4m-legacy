function [errCode, toplevel] = petscKSPSetOptionsPrefix(ksp, prefix)
%Sets the prefix used for searching for all KSP options in the database.
%   errCode = petscKSPSetOptionsPrefix(ksp, prefix)
%
%   ksp    - the KSP context
%   prefix - the prefix string to prepend to all KSP option requests
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscKSPSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  KSPSetOptionsPrefix(KSP ksp,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOptionsPrefix.html

%#codegen -args {PetscKSP, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscKSPSetOptionsPrefix:InputError', ...
            'The argument must be a null-terminated string.')
    end
    
    errCode = coder.ceval('KSPSetOptionsPrefix', t_ksp, coder.rref(prefix));

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
