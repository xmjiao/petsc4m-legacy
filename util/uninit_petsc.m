function uninit_petsc
% Finalize PETSc. 
% It is called automatically in Octave at exit if init_petsc was called

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
catch
end

end
