function [pc, errCode, toplevel] = petscPCDestroy(pc)
%Destroys PC context.
%
%  [pc, errCode] = petscPCDestroy(pc)
%
%  SEE ALSO: petscPCCreate, petscPCSetUp, petscPCSolve
%
% PETSc C interface:
%   PetscErrorCode PCDestroy(PC *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCDestroy.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = PetscPC(pc);
    
    errCode = coder.ceval('PCDestroy', coder.ref(t_pc));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCDestroy returned error code %d\n', errCode)
    end
    
    if toplevel
        % Create a MATLAB opaque object if the req is a MATLAB opaque object.
        pc = opaque_obj('PC', t_pc);
    else
        pc = t_pc;
    end
end
end
