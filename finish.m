% Finalize PETSc. 
% It is called automatically when MATLAB terminates if init_petsc was called

try
    uninit_petsc;
catch
end