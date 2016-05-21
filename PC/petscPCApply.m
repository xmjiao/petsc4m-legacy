function [errCode, toplevel] = petscPCApply(pc, b, x)
%Applies the preconditioner to a vector.
%
%  errCode = petscPCApply(pc, b)
%
%  solves the linear system with b as the RHS and saves the solution into b.
%     pc - iterative context obtained from petscPCCreate()
%     b	  - the right hand side vector
%
%  errCode = petscPCApply(pc, b, x)
%
%  solves the linear system and saves the solution into vector x.
%
%  SEE ALSO: petscPCSetUp, petscPCApplyTranspose
%
% PETSc C interface:
%   PetscErrorCode PCApply(PC pc,Vec b,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCApply.html

%#codegen -args {PetscPC, PetscVec, PetscVec}
%#codegen petscPCApply_2args -args {PetscPC, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_pc = PetscPC(pc);
    t_b = PetscVec(b);
    
    if nargin==2
        t_x = t_b;
    else
        t_x = PetscVec(x);
    end
    
    errCode = coder.ceval('PCApply', t_pc, t_b, t_x);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCApply returned error code %d\n', errCode)
    end
end
end
