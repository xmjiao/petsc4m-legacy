function [errCode, toplevel] = petscKSPSetResidualHistory(ksp, varargin)
% Sets the array used to hold the residual history. If set, this array
% will contain the residual norms computed at each iteration of the solver.
%
%  errCode = petscKSPSetResidualHistory(ksp)
%  errCode = petscKSPSetResidualHistory(ksp, na)
%  errCode = petscKSPSetResidualHistory(ksp, na, reset) sets the maximum
%  size of the residual history. The argument reset indicates whether
%  the history counter should be reset to zero for each new linear solve.
%  The space for the residual history will be allocated by PETSc and can be
%  retrieved by petscKSPGetResidualHistory.
%
%  SEE ALSO: petscKSPGetResidualHistory
%
% PETSc C interface:
%   PetscErrorCode  KSPSetResidualHistory(KSP ksp,PetscReal a[],PetscInt na,PetscBool reset)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetResidualHistory.htm

%#codegen -args {PetscKSP}
%#codegen petscKSPSetResidualHistory_2args -args {PetscKSP, int32(0)}
%#codegen petscKSPSetResidualHistory_3args -args {PetscKSP, int32(0), int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    if nargin>=2; na = int32(varargin{1}); else na = PETSC_DECIDE; end
    if nargin>=3; reset = int32(varargin{2}); else reset = PETSC_TRUE; end
    
    a = coder.opaque('PetscReal *', 'NULL');
    errCode = coder.ceval('KSPSetResidualHistory', t_ksp, ...
        a, na, reset);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', ...
            'petscKSPSetResidualHistory returned error code %d\n', errCode)
    end
end
end
