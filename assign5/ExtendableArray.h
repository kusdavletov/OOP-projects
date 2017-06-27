// Expandable integer array class
#ifndef EARRAY_H
#define EARRAY_H
#include <ostream>
using namespace std;
class ExtendableArray;

class ElementRef {
    private:
        ExtendableArray *intArrayRef;
        int index; // the index to the element
    public:
        ElementRef( ExtendableArray& theArray, int i );  //work
        ElementRef( const ElementRef& other ); // work
        ~ElementRef();
        ElementRef& operator=( const ElementRef& rhs ); //work
        ElementRef& operator=( int val ); //work
        operator int() const;
};

class ExtendableArray {
    private:
        int *arrayPointer; // integer array pointer
        int size; // the size of the array
    public:
        ExtendableArray(); //work
        ExtendableArray(const ExtendableArray& other); //work
        ~ExtendableArray(); //work
        ExtendableArray& operator=(const ExtendableArray& rhs); //work
        ElementRef operator[](int i);  //work
        friend class ElementRef; // ElementRef class can access my private members
        friend ostream& operator<< (ostream& o, const ExtendableArray& t){
            for(int i = 0; i < t.size; i++){
                o << t.arrayPointer[i] << " ";
            }
            return o;
        }
};

#endif // EARRAY_H