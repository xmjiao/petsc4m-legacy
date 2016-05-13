function [ksp, toplevel] = mptKSPSetup(Amat, ksptype, pctype, pcprefix)
% Sets up KSP using the given matrix (matrices).
%
% Syntax:
%  ksp = mptKSPSetup(A)
%  ksp = mptKSPSetup(A, ksptype)
%  ksp = mptKSPSetup(A, ksptype, pctype)
%  ksp = mptKSPSetup(A, ksptype, pctype, pcprefix)
%
% Description:
%  ksp = mptKSPSetup(A) sets up a KSP using matrix A.
%
%  ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP.
%
%  ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP
%    and the preconditioner.
%
%  ksp = mptKSPSetup(A, ksptype, pctype, pcpre) uses the option 
%    database with the given prefix to control the PC.
%
% See Also: mptKSPSolve, mptKSPCleanup

%#codegen -args {PetscMat, PetscKSPType, PetscPCType, coder.typeof(char(0), [1,inf])}
%#codegen mptKSPSetup_1arg -args {PetscMat}
%#codegen mptKSPSetup_2args -args {PetscMat, PetscKSPType}
%#codegen mptKSPSetup_3args -args {PetscMat, PetscKSPType, PetscPCType}

t_ksp = petscKSPCreate(petscObjectGetComm(Amat));

% Setup KSP
petscKSPSetOperators(t_ksp, Amat);
t_pc = petscKSPGetPC(t_ksp);

if nargin>1
    % Set KSP Types
    petscKSPSetType(t_ksp, ksptype);
    if nargin>2
        petscPCSetType(t_pc, pctype);
        if nargin>3
            petscPCSetOptionsPrefix(t_pc, pcprefix);
        end
    end
end

petscKSPSetFromOptions(t_ksp);
petscPCSetFromOptions(t_pc);
petscKSPSetUp(t_ksp);

toplevel = nargout>1;
ksp = PetscKSP(t_ksp, toplevel);

end
