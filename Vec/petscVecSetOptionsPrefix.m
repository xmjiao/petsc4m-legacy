function [errCode, toplevel] = petscVecSetOptionsPrefix(vec, prefix)
%Sets the prefix used for searching for all Vec options in the database.
%
%   errCode = petscVecSetOptionsPrefix(vec, prefix)
%
%   vec    - the Vec context
%   prefix - the prefix string to prepend to all Mat option requests.
%             It must be null terminated.
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscVecSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  VecSetOptionsPrefix(Vec v,const char prefix[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetOptionsPrefix.html

%#codegen -args {PetscVec, coder.typeof(char(0), [1, inf])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);

    toplevel = nargout>1;
    if ~isempty(prefix) && prefix(end) && (toplevel || m2c_debug)
        m2c_error('MPETSc:petscVecSetOptionsPrefix:InputError', ...
            'The argument must be a null-terminated string.')
    end
    
    errCode = coder.ceval('VecSetOptionsPrefix', t_vec, coder.rref(prefix));
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetOptionsPrefix returned error code %d\n', errCode)
    end
end

end
