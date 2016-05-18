function [errCode, toplevel] = petscPCSetType(pc, type)
%Builds PC for a particular solver.
%
%  errCode = petscPCSetType(pc, type) sets the type of the PC
%
%  SEE ALSO:  PetscPCSetType, petscPCCreate
%
% PETSc C interface:
%   PetscErrorCode  PCSetType(PC pc, PCType type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetType.html

%#codegen -args {PetscPC, PetscPCType}

errCode = int32(-1);

if ~coder.target('MATLAB')
    if ischar(type)
        errCode = coder.ceval('PCSetType', PetscPC(pc), coder.rref(type));
    else % If type is an opaque object of PCType, do not pass by reference.
        errCode = coder.ceval('PCSetType', PetscPC(pc), type);
    end

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCSetType returned error code %d\n', errCode)
    end
end
end
