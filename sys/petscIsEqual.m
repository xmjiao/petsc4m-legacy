function isn = petscIsEqual(obj1, obj2)
% Determine whether two given objects are equal

isn = ~isstruct(obj) && obj1==obj2 || ...
    isstruct(obj) && isequal(obj1.data, obj2.data);
