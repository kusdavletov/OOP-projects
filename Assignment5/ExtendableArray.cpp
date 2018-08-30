#include "ExtendableArray.h"
#include <iostream>

using namespace std;

ElementRef::ElementRef(ExtendableArray& theArray, int i){  //Constructor of ElementRef
    index = i;  //assigning the input values to ElementRef object (index and intArrayRef)
    intArrayRef = &theArray;
}

ElementRef::ElementRef(const ElementRef& other){  //Copy constructor of ElementRef
    index = other.index; //assigning the values of one ElementRef object to another
    intArrayRef = other.intArrayRef;
}

ElementRef::~ElementRef(){}  //Destructor should be empty

ElementRef& ElementRef::operator=(const ElementRef& rhs){  //= operator overloading when ElementRef assigned
    if (index >= intArrayRef->size){  //if index is bigger than array size, expand array
        ExtendableArray newArray;  //creating temporary variable
        newArray.size = index + 1;  //assigning the size
        newArray.arrayPointer = new int [newArray.size];  //creating arrayPointer with size (index + 1)
        for (int i = 0; i < newArray.size; i++){
            if (i < intArrayRef->size){  //if arrayPointer previously existed, then copy it
                newArray.arrayPointer[i] = intArrayRef->arrayPointer[i];
            }
            else{  //if not, assign 0 value
                newArray.arrayPointer[i] = 0;
            }
        }
        //assigning newArray to intArrayRef
        *intArrayRef = newArray;
        intArrayRef->size = newArray.size;
    }
    if (rhs.index >= rhs.intArrayRef->size){  //if rhs index is out of range assign 0 value
        intArrayRef->arrayPointer[index] = 0;
    }
    else{ //else assign rhs arrayPointer value at index
        intArrayRef->arrayPointer[index] = rhs.intArrayRef->arrayPointer[rhs.index];
    }
    return *this;
}

ElementRef& ElementRef::operator=(int val){  //= operator overloading when value assigned
    if (index >= intArrayRef->size){  //if index is bigger than array size, expand array
        ExtendableArray newArray;  //creating temporary variable
        newArray.size = index + 1;  //assigning the size
        newArray.arrayPointer = new int [newArray.size];  //creating arrayPointer with size (index + 1)
        for (int i = 0; i < newArray.size; i++){
            if (i < intArrayRef->size){
                newArray.arrayPointer[i] = intArrayRef->arrayPointer[i];  //if arrayPointer previously existed, then copy it
            }
            else{  //if not, assign 0 value
                newArray.arrayPointer[i] = 0;
            }
        }
        //assigning newArray to intArrayRef
        *intArrayRef = newArray;
        intArrayRef->size = newArray.size;
    }
    intArrayRef->arrayPointer[index] = val;  //assigning integer value
    return *this;
}

ElementRef::operator int() const{  //int operator
    if (index < intArrayRef->size){  //if index smaller than size then return arrayPointer[index]
        return intArrayRef->arrayPointer[index];
    }
    else{  //else if it is out of range return 0 value
        return 0;
    }
}

ExtendableArray::ExtendableArray(){  //ExtendableArray default constructor which allocates memory to hold 2 integers
    size = 2;
    arrayPointer = new int[size];  //allocating memory
    for (int i = 0; i < size; i++)
        arrayPointer[i] = 0;  //assigning 0 values
}

ExtendableArray::ExtendableArray(const ExtendableArray& other){ //Copy constructor of ExtendableArray
    size = other.size;  //making sizes equal
    arrayPointer = new int[size];  //allocating memory
    for (int i = 0; i < size; i++)
        arrayPointer[i] = other.arrayPointer[i];  //assigning values
}

ExtendableArray::~ExtendableArray(){ //Destructor
    delete [] arrayPointer;
}

ExtendableArray& ExtendableArray::operator=(const ExtendableArray& rhs){ //=operator overloading when ExtendableArray object assigned
    if (this == &rhs)  //if they are same just return *this
        return *this;
    delete [] arrayPointer;  //deleting the arrayPointer memory
    size = rhs.size;  //assigning the size
    arrayPointer = new int[size];  //allocating the memory of size
    for (int i = 0; i < size; i++)
        arrayPointer[i] = rhs.arrayPointer[i];  //assigning the values
    return *this;
}

ElementRef ExtendableArray::operator[](int i){  //[] operator overloading
    return ElementRef(*this, i);  //return the constructor of ElementRef with values (*this and i)
}
