function uninit_petsc
% Finalize PETSc. This is called automatically in Octave

if isoctave
    atexit('uninit_petsc', false)
end

try
    if exist(['petscInitialized.' mexext], 'file') && ...
            exist(['petscFinalized.' mexext], 'file')  && ...
            exist(['petscFinalize.' mexext], 'file')  && ...
            petscInitialized && ~petscFinalized
        petscFinalize;
    end
    
    uninit_mpi
catch
end

end
