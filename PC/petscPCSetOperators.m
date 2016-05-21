function [errCode, toplevel] = petscPCSetOperators(pc, Amat, Pmat)
%Sets the matrix associated with the linear system and a (possibly) 
%different one associated with the preconditioner. 
%
%  errCode = petscPCSetOperators(pc, Amat) sets the matrix to be Amat 
%  and use the same matrix to construct the preconditioner.
%
%     pc - iterative context obtained from petscPCCreate
%     Amat	  - the right hand side vector
%
%  errCode = petscPCSetOperators(pc, Amat, Pmat)
%
%  uses the matrix Pmat to construct the preconditioner.
%
%  SEE ALSO: petscPCCreate, petscPCSetUp, petscPCApply, petscPCDestroy
%
% PETSc C interface:
%   PetscErrorCode  PCSetOperators(PC pc,Mat Amat,Mat Pmat)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetOperators.html

%#codegen -args {PetscPC, PetscMat, PetscMat}
%#codegen petscPCSetOperators_AforP -args {PetscPC, PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_pc = PetscPC(pc);
    t_Amat = PetscMat(Amat);
    
    if nargin==2
        t_Pmat = t_Amat;
    else
        t_Pmat = PetscMat(Pmat);
    end
    
    errCode = coder.ceval('PCSetOperators', t_pc, t_Amat, t_Pmat);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetOperators returned error code %d\n', errCode)
    end
end
end
