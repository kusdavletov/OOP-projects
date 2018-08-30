#include <iostream>
#include "Iterator.h"

using namespace std;

int main(){
    Node n1("Node1 for Iterator");
    Node n2("Node2 for Iterator");
    Iterator t1(&n1);
    Iterator t2(&n2);
    cout << *t1 << endl;
    cout << *t2 << endl;
    if (t1.getCurr() == &n1 && t2.getCurr() == &n2){
        cout << "getCurr works!" << endl;
    }
    if (t1 != t2){
        cout << "!= operator works!" << endl;
    }
    if (t1 == t1){
        cout << "== operator works!" << endl;
    }
    return 0;
}
