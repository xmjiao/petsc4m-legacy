function [errCode, toplevel] = petscPCApplyTranspose(pc, b, x)
%Applies the transpose of preconditioner to a vector.
%
%  errCode = petscPCApplyTranspose(pc, b)
%
%  solves the linear system with b as the RHS and saves the solution into b.
%     pc - iterative context obtained from petscPCCreate()
%     b	  - the right hand side vector
%
%  errCode = petscPCApplyTranspose(pc, b, x)
%
%  solves the linear system and saves the solution into vector x.
%
%  SEE ALSO: petscPCCreate, petscPCSetUp, petscPCApply
%
% PETSc C interface:
%   PetscErrorCode PCApplyTranspose(PC pc,Vec b,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCApplyTranspose.html

%#codegen -args {PetscPC, PetscVec, PetscVec}
%#codegen petscPCApplyTranspose_2args -args {PetscPC, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_pc = PetscPC(pc);
    t_b = PetscVec(b);
    
    if nargin==2
        t_x = t_b;
    else
        t_x = PetscVec(x);
    end
    
    errCode = coder.ceval('PCApplyTranspose', t_pc, t_b, t_x);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCApplyTranspose returned error code %d\n', errCode)
    end
end
end
