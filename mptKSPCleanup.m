function [ksp, toplevel] = mptKSPCleanup(ksp) 
% Cleans up the KSP.
%
%   ksp = mptKSPCleanup(ksp) destropys the given KSP object.
%   It should be called whtn the KSP object is no longer needed, and 
%   no calls should be made to this KSP after this.
%
% See Also: mptKSPSetup, mptKSPSolve

%#codegen -args {PetscKSP}

% Destroy the KSP and solution vector
if nargout>1
    [ksp, ~, toplevel] = petscKSPDestroy(ksp);
else
    ksp = petscKSPDestroy(ksp);
end

end
