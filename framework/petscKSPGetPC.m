function [pc, errCode, toplevel] = petscKSPGetPC(ksp)
%Returns a pointer to the preconditioner context set with petscKSPSetPC.
%
%  [pc, errCode] = petscKSPGetPC(ksp, pc) gets the PC of the KSP
%
%  SEE ALSO:  petscKSPSetPC
%
% PETSc C interface:
%   PetscErrorCode  KSPGetPC(KSP ksp,PC *pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetPC.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = coder.opaque('PC');
    errCode = coder.ceval('KSPGetPC', PetscKSP(ksp), coder.wref(t_pc));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetPC returned error code %d\n', errCode)
    end
    
    if toplevel
        pc = opaque_obj('PC', t_pc);
    else
        pc = t_pc;
    end
end
end
