#ifndef __GENERICSET_H__
#define __GENERICSET_H__

#define MAX_ITEMS 30

#include <iostream>
using namespace std;

typedef int ItemType;

class GenericSet{
        protected: //because we need to use them in derived classes
                int size;
                ItemType values[MAX_ITEMS];
        public:
                GenericSet(); // Default Constructor - an empty generic set is created
                virtual void Insert(ItemType item)=0; // Insert function
                virtual void Delete(ItemType item)=0; // Delete function
                void Clear(); // Clear function - all items are removed from the generic set, and the size = 0
                int GetSize(); // GetSize function - returns value is the number of items in the generic set
                bool IsFull(); // IsFull function - returns true if the generic set is full, false otherwise
                bool IsEmpty(); // IsEmpty function - returns true if the generic set is empty, false otherwise
                friend std::ostream& operator<<(std::ostream& out, const GenericSet& s){
                        out << "{";
                        for (int i = 0; i < s.size; i++){
                                out << s.values[i] ;
                                if (i < s.size - 1) out << ", ";
                        }
                        out << "}";
                        return out;
                }
};

GenericSet::GenericSet(){ // Default Constructor - an empty generic set is created
    size = 0;
}

void GenericSet::Clear(){ // Clear function - all items are removed from the generic set, the size = 0
    size = 0;
}

int GenericSet::GetSize(){ // GetSize function - returns value is the number of items in the generic set
    return size;
}

bool GenericSet::IsFull(){  // IsFull function - returns true if the generic set is full, false otherwise
    if (size == MAX_ITEMS) // full if size is equal to MAX_ITEMS
        return true;
    else
        return false;
}

bool GenericSet::IsEmpty(){ // IsEmpty function - returns true if the generic set is empty, false otherwise
    if (size == 0) // empty if size is equal to 0
        return true;
    else
        return false;
}

template <class T> // class template means that functions can be used with any data types
class Set : public GenericSet{ // Set class is derived from GenericSet
    public:
        virtual void Insert(T item){ // overriding Insert() function for Set class
            bool exist = false; // variable to check whether item is in the values[]
            for (int i = 0; i < size; i++){ // checking whether item exists or not
                if (values[i] == item){
                    exist = true;
                    break;
                }
            }
            if (IsFull() == true && exist == false){ // if item is not in values[] and values[] is full - throw exception
                throw "Set Exception: No more space";
            }
            else if (exist == false){ // if item is not in values[], then add it
                values[size] = item;
                size += 1;
            }
        }
        virtual void Delete(T item){ // overriding Delete() function for Set class
            bool exist = false; // variable to check whether item is in the values[]
            int place; // variable for storing the position of the item in values[]
            for (int i = 0; i < size; i++){ // checking whether item exists or not
                if (values[i] == item){
                    exist = true;
                    place = i;
                    break;
                }
            }
            if (exist == false){ // if item is not in values[] then throw exception
                throw "Set Exception: Not found";
            }
            else {  // else delete the item from values[]
                for (int i = place; i < size - 1; i++){
                    values[i] = values[i + 1];
                }
                size -= 1;
            }
        }
};

template <class T> //class template means that functions can be used with any data types
class Bag : public GenericSet{ // Bag class is derived from GenericSet
    public:
        virtual void Insert(T item){ // overriding Insert() function for Bag class
            if (IsFull() == true){ // if values[] is full then throw exception
                throw "Bag Exception: No more space";
            }
            else{ // else insert item in values[]
                values[size] = item;
                size += 1;
            }
        }
        virtual void Delete(T item){
            bool exist = false; // variable to check whether item is in the values[]
            int place; // variable for storing the position of the item in values[]
            for (int i = size - 1; i >= 0; i--){ // checking whether item exists or not
                if (values[i] == item){
                    exist = true;
                    place = i; // i is starting from (size - 1) because we need to delete last same value as item
                    break;
                }
            }
            if (exist == false){ // if item is not in values[] then throw exception
                throw "Bag Exception: Not found";
            }
            else{ // else delete the item from values[]
                for (int i = place; i < size - 1; i++){
                    values[i] = values[i + 1];
                }
                size -= 1;
            }
        }
};

#endif

