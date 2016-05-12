function [ksp, toplevel] = mptKSPSetup(Amat, Pmat, ksptype, kspprefix, ...
    pctype, pcprefix, opts_in_string)
% Sets up KSP using the given matrix (matrices).
%
% Syntax:
%  ksp = mptKSPSetup(A)
%  ksp = mptKSPSetup(A, P)
%  ksp = mptKSPSetup(A, P, ksptype)
%  ksp = mptKSPSetup(A, P, ksptype, kspprefix)
%  ksp = mptKSPSetup(A, P, ksptype, kspprefix, pctype)
%  ksp = mptKSPSetup(A, P, ksptype, kspprefix, pctype, pcprefix)
%  ksp = mptKSPSetup(A, P, ksptype, kspprefix, pctype, pcprefix, opts_in_string)
%
% Description:
%  ksp = mptKSPSetup(A) sets up a KSP using matrix A.
%
%  ksp = mptKSPSetup(A, P) sets up the KSP using the given matrix A and
%    possibly another matrix P associated with the preconditioner.
%    In most cases, P=A, and mptKSPSetup(A, A) is the same as mptKSPSetup(A).
%
%  ksp = mptKSPSetup(A, P, ksptype, pctype) uses the specified type of the KSP.
%
%  ksp = mptKSPSetup(A, P, ksptype, pctype) also sets the type of the KSP
%    and the preconditioner.
%
%  ksp = mptKSPSetup(A, P, ksptype, pctype, ksppre, pcpre) uses the 
%    inserts additional options (in a character strings) into the option 
%    database and use those with the given prefix to control the KSP.
%
%  ksp = mptKSPSetup(A, P, ksptype, pctype, ksppre, pcpre, opts_in_string) 
%    inserts additional options (in a character strings) into the option 
%    database and use those with the given prefix to control the KSP.
%
% See Also: mptKSPSolve, mptKSPCleanup

%#codegen -args {PetscMat, PetscMat, PetscKSPType, coder.typeof(char(0), [1,inf]),
%#codegen PetscPCType, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}
%#codegen mptKSPSetup_1arg -args {PetscMat}
%#codegen mptKSPSetup_2args -args {PetscMat, PetscMat}
%#codegen mptKSPSetup_3args -args {PetscMat, PetscMat, PetscKSPType}
%#codegen mptKSPSetup_4args -args {PetscMat, PetscMat, PetscKSPType, 
%#codegen    coder.typeof(char(0), [1,inf])}
%#codegen mptKSPSetup_5args -args {PetscMat, PetscMat, PetscKSPType, 
%#codegen    coder.typeof(char(0), [1,inf]), PetscPCType}
%#codegen mptKSPSetup_6args -args {PetscMat, PetscMat, PetscKSPType, 
%#codegen    coder.typeof(char(0), [1,inf]), PetscPCType, coder.typeof(char(0), [1,inf])}

if nargout>1
    [ksp, ~, toplevel] = petscKSPCreate(petscObjectGetComm(Amat));
    t_ksp = PetscKSP(ksp);
else
    ksp = petscKSPCreate(petscObjectGetComm(Amat));
    t_ksp = ksp;
end

% Setup KSP
if nargin==1 || isempty(Pmat)
    petscKSPSetOperators(t_ksp, Amat);
else
    petscKSPSetOperators(t_ksp, Amat, Pmat);
end

if nargin>2
    % Set KSP and PC Types
    petscKSPSetType(t_ksp, ksptype);
end

if nargin>7
    petscOptionsInsertString(opts_in_string);
end

% Insert options into options database
if nargin>3 && ~isempty(kspprefix)
    petscKSPSetOptionsPrefix(t_ksp, kspprefix);
end

t_pc = petscKSPGetPC(t_ksp);
if nargin>4
    petscPCSetType(t_pc, pctype);
    if nargin>5
        petscPCSetOptionsPrefix(t_pc, pcprefix);
    end
end

petscKSPSetFromOptions(t_ksp);
petscPCSetFromOptions(t_pc);
petscKSPSetUp(t_ksp);
end
