function [ksp, time, toplevel] = mptKSPSetup(Amat, ksptype, pctype, pcopt)
% Sets up KSP using the given matrix (matrices).
%
% Syntax:
%  ksp = mptKSPSetup(A)
%  ksp = mptKSPSetup(A, ksptype)
%  ksp = mptKSPSetup(A, ksptype, pctype)
%  ksp = mptKSPSetup(A, ksptype, pctype, pcopt)
%
% Description:
%  ksp = mptKSPSetup(A) sets up a KSP using matrix A.
%
%  ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP.
%
%  ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP
%    and the preconditioner. Note that pctype can be NULL.
%
%  ksp = mptKSPSetup(A, ksptype, pctype, pcopt) aspecifies additional
%    control options for the preconditioner. It can be PETSC_MATSOLVER*,
%    which is useful when the ksptype is PETSC_KSPPREONLY, and the pctype
%    is a direct method (such as PETSC_PCLU or PETSC_PCCHOLESKY). Otherwise,
%    it may be 'left', 'right', or 'symmetric' (without null-terminator)
%    to choose to use left, right, or symmetric preconditioners. By
%    default, PETSc uses left preconditioners.
%
% See Also: mptKSPSolve, mptKSPCleanup

%#codegen -args {PetscMat, PetscKSPType, PetscPCType, PetscMatSolverPackage}
%#codegen mptKSPSetup_1arg -args {PetscMat}
%#codegen mptKSPSetup_2args -args {PetscMat, PetscKSPType}
%#codegen mptKSPSetup_3args -args {PetscMat, PetscKSPType, PetscPCType}

t_Amat = Amat;
t_ksp = petscKSPCreate(petscObjectGetComm(t_Amat));

if nargout>1;
    time = 0;
    comm = petscObjectGetComm(t_ksp);
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    t = mpi_Wtime();
end

% Setup KSP
petscKSPSetOperators(t_ksp, PetscMat(t_Amat));

if nargin>1
    if nargin>2
        hasPC = ~ischar(pctype) || ~isempty(pctype);
        hasOpt = nargin>3 && (~ischar(pcopt) || ~isempty(pcopt));
        
        if hasPC || hasOpt
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
            
            if hasOpt
                if isequal(pcopt, 'left')
                    petscKSPSetPCSide(t_ksp, PETSC_PC_LEFT);
                elseif isequal(pcopt, 'right')
                    petscKSPSetPCSide(t_ksp, PETSC_PC_RIGHT);
                elseif isequal(pcopt, 'symmetric')
                    petscKSPSetPCSide(t_ksp, PETSC_PC_SYMMETRIC);
                else
                    if ischar(pcopt) && pcopt(end)~=char(0)
                        % null-terminate the string if not terminated properly
                        pcopt0 = [pcopt char(0)];
                    else
                        pcopt0 = pcopt;
                    end
                    petscPCFactorSetMatSolverPackage(t_pc,pcopt0);
                end
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

if nargout>1
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    time = mpi_Wtime()-t;
end

toplevel = nargout>2;
ksp = PetscKSP(t_ksp, toplevel);

end
