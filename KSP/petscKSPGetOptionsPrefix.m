function [str, errCode, toplevel] = petscKSPGetOptionsPrefix(ksp)
%Gets the prefix used for searching for all KSP options in the database.
%   errCode = petscKSPGetOptionsPrefix(ksp, in_str)
%
%   ksp    - the KSP context
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscKSPGetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  KSPGetOptionsPrefix(KSP ksp,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetOptionsPrefix.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    % null-terminate the string.
    str0 = coder.opaque('const char *');    
    errCode = coder.ceval('KSPGetOptionsPrefix', t_ksp, coder.wref(str0));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetOptionsPrefix returned error code %d\n', errCode)
    end

    noprefx = int32(0); %#ok<NASGU>
    noprefx = coder.ceval('!', str0);
    n = int32(0); %#ok<NASGU>
    
    if ~noprefx
        n = coder.ceval('strlen', str0);
        str1 = zeros(1, n+1, 'uint8');
        coder.ceval('memcpy', coder.ref(str1), str0, n+1);
    else
        str1 = zeros(1, 0, 'uint8');
    end
        
    str = char(str1);
end
end
