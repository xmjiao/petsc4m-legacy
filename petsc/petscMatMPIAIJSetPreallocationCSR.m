function [errCode, toplevel] = petscMatMPIAIJSetPreallocationCSR(mat, ix, jx, vs)
%Allocates memory for a sparse parallel matrix in AIJ format (the default parallel PETSc format).
%
%  errCode = petscMatMPIAIJSetPreallocationCSR(mat, is, js, vs)
%
%   	B	- the matrix
%       ix	- the indices into j for the start of each local row (starts with zero)
%       jx	-  the column indices for each local row (starts with zero)
%
%  errCode = petscMatMPIAIJSetPreallocationCSR(mat, is, js, val)
%       vs	- optional values in the matrix
%
%  SEE ALSO: petscMatCreate, petscMatCreateSeqAIJ, petscMatSetValues,
%            petscMatMPIAIJSetPreallocation
%
% PETSc C interface:
%   PetscErrorCode  MatMPIAIJSetPreallocationCSR(Mat B,const PetscInt i[],const PetscInt j[], const PetscScalar v[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMPIAIJSetPreallocationCSR.html

%#codegen -args {PetscMat, coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}
%#codegen petscMatMPIAIJSetPreallocationCSR_Indexonly -args {PetscMat,
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1])}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    if nargin==3
        errCode = coder.ceval('MatMPIAIJSetPreallocationCSR', t_mat,...
            coder.rref(ix), coder.rref(jx), coder.opaque('PetscScalar *', 'NULL'));
    else
        errCode = coder.ceval('MatMPIAIJSetPreallocationCSR', t_mat,...
            coder.rref(ix), coder.rref(jx), coder.rref(vs));
    end
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMPIAIJSetPreallocationCSR returned error code %d\n', errCode)
    end
end
end
