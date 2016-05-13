function [type, errCode, toplevel] = petscKSPGetType(ksp)
%Gets the KSP type as a KSPType object from the KSP object.
%
%  [type, errCode] = petscKSPGetType(ksp) gets the type of the KSP
%
%  SEE ALSO:  petscKSPSetType
%
% PETSc C interface:
%   PetscErrorCode  KSPGetType(KSP ksp, KSPType *type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetType.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_type = coder.opaque('KSPType');
    errCode = coder.ceval('KSPGetType', PetscKSP(ksp), coder.wref(t_type));
    
    toplevel = nargout>2;
    type = PetscKSPType(t_type, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetType returned error code %d\n', errCode)
    end
end
end
