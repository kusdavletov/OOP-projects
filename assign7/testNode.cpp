#include <iostream>
#include "Node.h"

using namespace std;

int main(){
    Node n1;
    Node n2("Node2");
    Node n3("Node3", &n1);
    Node n4("Node4", &n2);
    cout << "Node1: " << n1.getWord() << endl;
    cout << "Node2: " << n2.getWord() << endl;
    cout << "Node3: " << n3.getWord() << endl;
    cout << "Node4: " << n4.getWord() << endl;
    if (n3.getPrev() == &n1 && n1.getNext() == &n3){
        cout << "Node1 -> Node3" << endl;
    }
    if (n4.getPrev() == &n2 && n2.getNext() == &n4){
        cout << "Node2 -> Node4" << endl;
    }
    n1.setWord("Node1");
    cout << "Node1: " << n1.getWord() << endl;
    n3.setNext(&n2);
    n2.setPrev(&n3);
    if (n3.getPrev() == &n1 && n1.getNext() == &n3 && n3.getNext() == &n2 && n2.getPrev() == &n3 && n2.getNext() == &n4 && n4.getPrev() == &n2){
        cout << "Node1 -> Node3 -> Node2 -> Node4" << endl;
    }
    return 0;
}
