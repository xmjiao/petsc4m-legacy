function [ksp, time] = petscKSPSetup(Amat, ksptype, pctype, pcopt)
% Sets up KSP using the given matrix (matrices).
%
% Syntax:
%  ksp = petscKSPSetup(A)
%  ksp = petscKSPSetup(A, ksptype)
%  ksp = petscKSPSetup(A, ksptype, pctype)
%  ksp = petscKSPSetup(A, ksptype, pctype, pcopt)
%  [ksp, time] = petscKSPSetup(...)
%
% Description:
%  ksp = petscKSPSetup(A) sets up a KSP using matrix A.
%
%  ksp = petscKSPSetup(A, ksptype) uses the specified type of the KSP.
%
%  ksp = petscKSPSetup(A, ksptype, pctype) also sets the type of the KSP
%    and the preconditioner. Note that pctype can be NULL.
%
%  ksp = petscKSPSetup(A, ksptype, pctype, pcopt) aspecifies additional
%    control options for the preconditioner. It can be PETSC_MATSOLVER*,
%    which is useful when the ksptype is PETSC_KSPPREONLY, and the pctype
%    is a direct method (such as PETSC_PCLU or PETSC_PCCHOLESKY). Otherwise,
%    it may be 'left', 'right', or 'symmetric' (without null-terminator)
%    to choose to use left, right, or symmetric preconditioners. By
%    default, PETSc uses left preconditioners.
%
% See Also: petscKSPDriver, petscKSPCleanup

t_Amat = Amat;
ksp = petscKSPCreate(petscObjectGetComm(t_Amat));
t_pc = petscKSPGetPC(ksp);

% Setup KSP
petscKSPSetOperators(ksp, PetscMat(t_Amat));

if nargin>1
    if nargin>2
        hasPC = ~ischar(pctype) || ~isempty(pctype);
        hasOpt = nargin>3 && (~ischar(pcopt) || ~isempty(pcopt));
        
        if hasPC || hasOpt           
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
                    petscKSPSetPCSide(ksp, PETSC_PC_LEFT);
                elseif isequal(pcopt, 'right')
                    petscKSPSetPCSide(ksp, PETSC_PC_RIGHT);
                elseif isequal(pcopt, 'symmetric')
                    petscKSPSetPCSide(ksp, PETSC_PC_SYMMETRIC);
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
        petscKSPSetType(ksp, ksptype0);
    end
end

if nargin<=3 || isempty(pcopt)
    % Use right-preconditioner by default
    petscKSPSetPCSide(ksp, PETSC_PC_RIGHT);
end

petscKSPSetFromOptions(ksp);

if nargout>1
    time = double(0);
    comm = petscObjectGetComm(ksp);
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    t = mpi_Wtime();
end

petscKSPSetUp(ksp);

if nargout>1
    % When timing the run, use mpi_Barrier for more accurate results.
    mpi_Barrier(comm);
    time = mpi_Wtime()-t;
end
end
