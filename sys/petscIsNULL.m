function isn = petscIsNULL(obj)
% Determine whether a given object is a null opointer of a particular type.
%
%    isn = petscIsNULL(obj)

isn = m2c_isnull(obj);
