function [Amat, Pmat, errCode, toplevel] = petscPCGetOperators(pc)
% Gets the matrix operator from the preconditioner context.
%
%  [Amat, Pmat, errCode] = petscPCGetOperators(pc) gets the matrix operators. 
%
% Note: This function is to be useful when calling PCCreate and PCDestroy manually.
%
%  SEE ALSO:  petscPCSetOperators
%
% PETSc C interface:
%   PetscErrorCode  PCGetOperators(PC ksp,Mat *Amat,Mat *Pmat)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCGetOperators.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~isempty(coder.target)
    Amat_t = coder.opaque('Mat');
    Pmat_t = coder.opaque('Mat');
    errCode = coder.ceval('PCGetOperators', PetscPC(pc), coder.wref(Amat_t), coder.wref(Pmat_t));
    
    toplevel = nargout>3;
    Amat = PetscMat(Amat_t, toplevel);
    Pmat = PetscMat(Pmat_t, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCGetOperators returned error code %d\n', errCode)
    end
end
end
