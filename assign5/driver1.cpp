#include "ExtendableArray.h"
#include <iostream>
using namespace std;

int main() {
    ExtendableArray a1;
    cout << a1 << endl; //0 0
    cout << &a1 << endl;
    for (int i = 0; i < 20; i++)
        a1[i] = i;
    cout << a1 << endl; //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    cout << &a1 << endl;
    ExtendableArray a2(a1);
    cout << a2 << endl; //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    cout << &a2 << endl;
    ExtendableArray a3;
    a3 = a1;
    cout << a3 << endl; //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    cout << &a3 << endl; cout << "s";
    cout << a3[10000000000] << endl; //0
    a1[22] = 5;
    cout << a1 << endl; //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 0 0 5
    cout << &a1 << endl;
    cout << a3 << endl; //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 0 0 5
    cout << &a3 << endl;
    a1[10] = a2[10000000000];
    cout << a1[10] << endl; //0
    ExtendableArray a4 = a1;
    cout << a4 << endl;
    cout << &a4 << endl;
    return 0;
}
