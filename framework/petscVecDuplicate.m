function [vec_out, errCode, toplevel] = petscVecDuplicate(vec_in)
%Creates a new vector of the same type as an existing vector.
%
%  [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but
%     it does not copy the entries of the input vector. The user is
%     responsible freeing the memory by calling petscVecDestroy.
%
%  SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate
%
% PETSc C interface:
%   PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec_out = coder.opaque('Vec');
    
    errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode)
    end
    
    if toplevel
        vec_out = opaque_obj('Vec', t_vec_out);
    else
        vec_out = t_vec_out;
    end
end
end
