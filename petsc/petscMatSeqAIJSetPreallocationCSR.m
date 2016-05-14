function [errCode, toplevel] = petscMatSeqAIJSetPreallocationCSR(mat, ix, jx, vs)
%Allocates memory for a sparse sequential matrix in AIJ format.
%
%  errCode = petscMatSeqAIJSetPreallocationCSR(mat, is, js, vs)
%
%   	B	- the matrix
%       ix	- the indices into j for the start of each row (starts with zero)
%       jx	- the column indices for each row (starts with zero) these must be sorted for each row
%
%  errCode = petscMatSeqAIJSetPreallocationCSR(mat, is, js, val)
%       vs	- optional values in the matrix
%
%  SEE ALSO: petscMatCreate, petscMatCreateSeqAIJ, petscMatSetValues,
%            petscMatSeqAIJSetPreallocation
%
% PETSc C interface:
%   PetscErrorCode MatSeqAIJSetPreallocationCSR(Mat B,const PetscInt i[],const PetscInt j[],const PetscScalar v[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSeqAIJSetPreallocationCSR.html

%#codegen -args {PetscMat, coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}
%#codegen petscMatSeqAIJSetPreallocationCSR_Indexonly -args {PetscMat,
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    if nargin==3
        errCode = coder.ceval('MatSeqAIJSetPreallocationCSR', t_mat,...
            coder.rref(ix), coder.rref(jx), coder.opaque('PetscScalar *', 'NULL'));
    else
        errCode = coder.ceval('MatSeqAIJSetPreallocationCSR', t_mat,...
            coder.rref(ix), coder.rref(jx), coder.rref(vs));
    end
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSeqAIJSetPreallocationCSR returned error code %d\n', errCode)
    end
end
end
