function [reshis, errCode, toplevel] = petscKSPGetResidualHistory(ksp)
%Gets the array used to hold the residual history and the number of
%residuals it contains.
%
%  [rehis, errCode] = KSPGetResidualHistory(ksp) returns a real array
%  containing the residual history.
%
%  SEE ALSO: petscKSPSetResidualHistory
%
% PETSc C interface:
%   PetscErrorCode  KSPGetResidualHistory(KSP ksp, const PetscReal *a[], PetscInt *na)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetResidualHistory.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    
    a = coder.opaque('const PetscReal *', 'NULL');
    na = int32(0);
    errCode = coder.ceval('KSPGetResidualHistory', t_ksp, ...
        coder.wref(a), coder.wref(na));
    
    reshis = zeros(na, 1);
    coder.ceval('memcpy', coder.ref(reshis), a, int32(na*8));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetResidualHistory returned error code %d\n', errCode)
    end
end
end
