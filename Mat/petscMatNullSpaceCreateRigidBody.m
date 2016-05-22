function [nullsp, errCode, toplevel] = petscMatNullSpaceCreateRigidBody(coords)
%Create rigid body modes from coordinates.
%
%  [nullsp, errCode] = petscMatNullSpaceCreateRigidBody(coords)
%      coords - block of coordinates of each node. Must have block size set
%
%  SEE ALSO: petscMatNullSpaceCreate
%
% PETSc C interface:
%   PetscErrorCode MatNullSpaceCreateRigidBody(Vec coords,MatNullSpace *sp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNullSpaceCreateRigidBody.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullsp = coder.opaque('MatNullSpace');
    t_coords = PetscVec(coords);
    
    
    errCode = coder.ceval('MatNullSpaceCreateRigidBody', ...
        t_coords, coder.wref(t_nullsp));
    
    toplevel = nargout>2;
    nullsp = PetscMatNullSpace(t_nullsp, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNullSpaceCreateRigidBody returned error code %d\n', errCode)
    end
end
end
