## Description
GenericSet is a class template so that any data type can be stored in a set or bag object. It is an abstract class template, since it has two pure virtual functions, Insert() and Delete(). Set and Bag are two class templates derived from GenericSet. 

They are can be used with any data types. A set is a collection of objects which must have distinct values, while a bag is a collection of objects which can have equivalent values. In this problem, we assume that a set or a bag can contain 30 objects at maximum.

Insert() and Delete() in Set:

If a set is full and Insert() function is called, a C-string exception ”Set Exception: No more space” is thrown to a caller function. If an item is already in the set, the item is not inserted into the set and no exception is thrown even if the set is already full. If there are spaces in set, each item is inserted into the member array (called values) in insertion order. I.e., the first inserted data item is stored in values[0], the second item in values[1], and so on. Delete() function searches and deletes an item provided as the parameter from the set if it is in the set. The insertion order is preserved even if an item is deleted in the middle of the set. If there’s no such item in a set, Delete() function is throwing a C-string exception ”Set Exception: Not found”.

Insert() and Delete() in Bag:

If a bag is full and Insert() function is called, a C-string exception ”Bag Exception: No more space” is thrown to a caller function. If there are spaces in the bag, an item is inserted into the member array in insertion order, regardless of whether the same item is already in the bag or not (unlike Set). Delete() function searches and deletes an item provided as the parameter from the bag if it is in the bag. The insertion order is preserved even if an item is deleted in the middle of the bag. If there are multiple items with the parameter value, the last inserted item is deleted. For example, consider a bag = {1, 3, 4, 1, 2}. After deleting item 1, the bag is {1, 3, 4, 2}. If there’s no such item in a bag, Delete() function is throwing a C- string exception ”Bag Exception: Not found”.
