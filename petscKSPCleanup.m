function ksp = petscKSPCleanup(ksp) 
% Cleans up the KSP.
%
%   ksp = petscKSPCleanup(ksp) destropys the given KSP object.
%   It should be called whtn the KSP object is no longer needed, and 
%   no calls should be made to this KSP after this.
%
% See Also: petscKSPSetup, petscKSPDriver

% Destroy the KSP and solution vector
ksp = petscKSPDestroy(ksp);

end
