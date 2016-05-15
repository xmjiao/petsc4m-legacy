function iseq = petscIsEqual(obj1, obj2)
% Determine whether two given objects are equal

if ischar(obj1) && ischar(obj2) || isstruct(obj1) && isstruct(obj2)
    iseq = isequal(obj1, obj2);
else
    iseq = obj1==obj2;
end
