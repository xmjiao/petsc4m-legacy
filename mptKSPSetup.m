function [ksp, time, toplevel] = mptKSPSetup(Amat, ksptype, pctype, solpack)
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

time = 0;
if nargout>1; t=m2c_wtime(); end

% Setup KSP
petscKSPSetOperators(t_ksp, Amat);

if nargin>1
    if nargin>2
        hasPC = ~ischar(pctype) || ~isempty(pctype);
        hasSolver = nargin>3 && (~ischar(solpack) || ~isempty(solpack));
        
        if hasPC || hasSolver
            t_pc = petscKSPGetPC(t_ksp);
            
            if hasPC
                if ischar(pctype) && pctype(end)~=char(0)
                    % null-terminate the string if not terminated properly
                    pctype0 = [pctype char(0)];
                else
                    pctype0 = pctype;
                end
                petscPCSetType(t_pc, pctype0);
            end
            
            if hasSolver
                if ischar(solpack) && solpack(end)~=char(0)
                    % null-terminate the string if not terminated properly
                    solpack0 = [solpack char(0)];
                else
                    solpack0 = solpack;
                end
                petscPCFactorSetMatSolverPackage(t_pc,solpack0);
            end
        end
    end
    
    if ischar(ksptype) && ~isempty(ksptype) && ksptype(end)~=0
        % null-terminate the string if not terminated properly
        ksptype0 = [ksptype char(0)];
    else
        ksptype0 = ksptype;
    end
    if ischar(ksptype0) && ~isempty(ksptype0) || ~ischar(ksptype0)
        % Set KSP Types
        petscKSPSetType(t_ksp, ksptype0);
    end
end

petscKSPSetFromOptions(t_ksp);

petscKSPSetUp(t_ksp);
if nargout>1; time=m2c_wtime()-t; end

toplevel = nargout>2;
ksp = PetscKSP(t_ksp, toplevel);

end
