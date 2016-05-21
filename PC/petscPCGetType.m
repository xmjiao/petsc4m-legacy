function [type, errCode, toplevel] = petscPCGetType(pc)
%Gets the PC type as a PCType object from the PC object.
%
%  [type, errCode] = petscPCGetType(pc) gets the type of the PC
%
%  SEE ALSO:  petscPCSetType
%
% PETSc C interface:
%   PetscErrorCode  PCGetType(PC pc, PCType *type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCGetType.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~isempty(coder.target)
    t_type = coder.opaque('PCType');
    errCode = coder.ceval('PCGetType', PetscPC(pc), coder.wref(t_type));
    
    toplevel = nargout>2;
    type = PetscPCType(t_type, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCGetType returned error code %d\n', errCode)
    end
end
end
