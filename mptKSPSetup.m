function [ksp, toplevel] = mptKSPSetup(Amat, ksptype, pctype, solpack)
% Sets up KSP using the given matrix (matrices).
%
% Syntax:
%  ksp = mptKSPSetup(A)
%  ksp = mptKSPSetup(A, ksptype)
%  ksp = mptKSPSetup(A, ksptype, pctype)
%  ksp = mptKSPSetup(A, ksptype, pctype, solpack)
%
% Description:
%  ksp = mptKSPSetup(A) sets up a KSP using matrix A.
%
%  ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP.
%
%  ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP
%    and the preconditioner. Note that pctype can be NULL.
%
%  ksp = mptKSPSetup(A, ksptype, pctype, solpack) configures the KSP
%    solver using the specified solver package. It is useful only when
%    pctype is PCLU, PCILU, or PCICC.
%
% See Also: mptKSPSolve, mptKSPCleanup

%#codegen -args {PetscMat, PetscKSPType, PetscPCType, PetscMatSolverPackage}
%#codegen mptKSPSetup_1arg -args {PetscMat}
%#codegen mptKSPSetup_2args -args {PetscMat, PetscKSPType}
%#codegen mptKSPSetup_3args -args {PetscMat, PetscKSPType, PetscPCType}

t_ksp = petscKSPCreate(petscObjectGetComm(Amat));

% Setup KSP
petscKSPSetOperators(t_ksp, Amat);

if nargin>1
    if nargin>2
        hasPC = ~petscIsNULL(pctype);
        hasSolver = nargin>3 && ~petscIsNULL(solpack);
        
        if hasPC || hasSolver
            t_pc = petscKSPGetPC(t_ksp);
            
            if hasPC
                if ischar(pctype) && pctype(end)~=0
                    m2c_error('PC type must be a null-terminated string.');
                end
                petscPCSetType(t_pc, pctype);
            end
            
            if hasSolver
                petscPCFactorSetMatSolverPackage(t_pc,solpack);
            end
        end
    end
    
    if ischar(ksptype) && ksptype(end)~=0
        m2c_error('KSP type must be a null-terminated string.');
    end
    % Set KSP Types
    petscKSPSetType(t_ksp, ksptype);
end

petscKSPSetFromOptions(t_ksp);
petscKSPSetUp(t_ksp);

toplevel = nargout>1;
ksp = PetscKSP(t_ksp, toplevel);

end
