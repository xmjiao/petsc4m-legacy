function [info, errCode, toplevel] = petscMatGetInfo(mat, flag)
%Returns information about matrix storage (number of nonzeros, memory, etc.).
%
%  [info, errCode] = petscMatGetInfo(mat)
%   gets parameters of a local matrix. Same as petscMatGetInfo(mat, MAT_LOCAL)
%  	    mat   - the matrix
%
%  [info, errCode] = petscMatGetInfo(mat, flag)
%       flag  - the type of parameters to be returned (MAT_LOCAL -
%               local matrix, MAT_GLOBAL_MAX - maximum over all processors,
%               MAT_GLOBAL_SUM - sum over all processors). The call is
%               collective if flag is MAT_GLOBAL_MAX or MAT_GLOBAL_SUM.
%
% PETSc C interface:
%   PetscErrorCode MatGetRow(Mat mat,PetscInt row,PetscInt *ncols,
%       PetscErrorCode MatGetInfo(Mat mat,MatInfoType flag,MatInfo *info)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetInfo.html#MatGetInfo

%#codegen -args {PetscMat, int32(0)}
%#codegen petscMatGetInfo_Local -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    if nargin<2
        flag = PETSC_MAT_LOCAL;
    end
    
    t_info = coder.opaque('MatInfo');
    errCode = coder.ceval('MatGetInfo', t_mat, flag, coder.wref(t_info));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscMatGetInfo returned error code %d\n', errCode)
    end
    
    nbytes = uint32(0); %#ok<NASGU>
    nbytes = coder.ceval('sizeof', t_info);
    
    [info, nfields] = PetscMatInfo;
    
    if nfields*8 < nbytes && m2c_debug
        m2c_error('petscMatGetInfo:WrongSize', ...
            'There are %d fields in PetscMatInfo but %d fields in MatInfo.', ...
            nfields, bitshift(nbytes, -3));
    end
    
    % Copy MatInfo out
    coder.ceval('memcpy', coder.wref(info), coder.rref(t_info), nbytes);
end
end
