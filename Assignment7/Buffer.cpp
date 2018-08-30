#include "Buffer.h"
#include <iostream>

Buffer::Buffer(){ // default constructor - creates empty linked list of count = 0
    head = NULL;
    count = 0;
}

Buffer::Buffer(const Buffer &other){ // copy constructor for buffer creates a deep copy, of the ll, and stores it in other calls copy()
    head = NULL;
    count = 0;
    copy(other);
}

Buffer::~Buffer(){ // destructor - calls clear();
    clear();
}

Buffer& Buffer::operator=(const Buffer &original){ // overloaded assignment operator - calls copy()
    copy(original);
    return *this;
}

Node* Buffer::getHead(){ // accessor - returns the head
    return head;
}

Node* Buffer::getTail(){ // accessor - returns the tail node
    return head->getPrev();
}

// returns the string in the head node of the ll, this operation is not valid for an empty ll (i.e. buffer)
// (If it is called on an empty buffer, return an empty string "".)
std::string Buffer::getHeadElement(){
    if (count == 0)
        return std::string("");
    else
        return head->getWord();
}

// returns the string in the tail node of the ll, this operation is not valid for an empty ll  (i.e. buffer)
// (If it is called on an empty buffer, return an empty string "".)
std::string Buffer::getTailElement(){
    if (count == 0)
        return std::string("");
    else
        return getTail()->getWord();
}

// creates a node containing str, adds the string at the head of the ll
// (i.e. before the current head node), after the operation, head node is the newly added one
void Buffer::produceAtHead(const std::string str){
    if (count == 0){
        Node *new_head = new Node(str);
        head = new_head;
        count += 1;
        return;
    }
    Node *new_head = new Node(str);
    new_head->setNext(getHead());
    new_head->setPrev(getTail());
    getTail()->setNext(new_head);
    getHead()->setPrev(new_head);
    head = new_head;
    count += 1;
}

// creates a node containing str, adds the string at the end of the ll
// (i.e. after the current tail node)
void Buffer::produceAtTail(const std::string str){
    if (count == 0){
        Node *new_head = new Node(str);
        head = new_head;
        count += 1;
        return;
    }
    Node *new_tail = new Node(str);
    new_tail->setNext(getHead());
    new_tail->setPrev(getTail());
    getTail()->setNext(new_tail);
    getHead()->setPrev(new_tail);
    count += 1;
}

// inserts Node containing "str" into the ll in front of "pos"
// return an iterator that points to the the newly inserted elements.
// any iterators after pos are considered invalid
Iterator Buffer::produceAtMiddle(Iterator pos, const std::string str){
    Node *new_middle = new Node(str);
    new_middle->setNext(pos.getCurr());
    new_middle->setPrev((pos - 1).getCurr());
    (pos - 1).getCurr()->setNext(new_middle);
    pos.getCurr()->setPrev(new_middle);
    count += 1;
    return pos;
}

// buffer must not be empty before calling this, deletes the first element (i.e. current head node)
void Buffer::consumeAtHead(){
    if (count == 0)
        return;
    else if (count == 1){
        delete head;
        count -= 1;
        return;
    }
    else{
        head->getNext()->setPrev(head->getPrev());
        head->getPrev()->setNext(head->getNext());
        Node *temp = head;
        head = head->getNext();
        delete temp;
        count -= 1;
    }
}

// buffer must not be empty before calling this, deletes the last element (i.e. current tail node)
void Buffer::consumeAtTail(){
    if (count == 0)
        return;
    else if (count == 1){
        delete head;
        count -= 1;
        return;
    }
    else{
        Node *temp = getTail();
        getTail()->getPrev()->setNext(head);
        head->setPrev(getTail()->getPrev());
        delete temp;
        count -= 1;
    }
}

void Buffer::consume(Iterator it){ // "it" is pointing to the element to be removed
    Node *temp = it.getCurr();
    (it - 1).getCurr()->setNext((it + 1).getCurr());
    (it + 1).getCurr()->setPrev((it - 1).getCurr());
    delete temp;
    count -= 1;
}

// erases all nodes in the range [s,t), s is erased and all nodes up to but not including t are erased
void Buffer::consume(Iterator s, Iterator t){
    if (s == t){
        return;
    }
    consume(s + 1, t);
    consume(s);
}

unsigned Buffer::size() const{ // returns the number of elements in the ll
    return count;
}

bool Buffer::isEmpty(){ // returns true if the ll is empty, otherwise it returns false
    if (count == 0)
        return true;
    else
        return false;
}

// brackets operator allows indexing into the ll, "fakes" random access to the ith element of the ll
// returns contents of ith element of the ll, if ll looks like: we -> are -> family ->
// then element 2 would be "family", remember the first element is the 0th element
std::string& Buffer::operator[](int i) const{
    Iterator it = head;
    it += i;
    return it.getCurr()->getWord();
}

Iterator Buffer::getHeadItr(){ // returns the iterator pointing to the first node in the ll
    return Iterator(head);
}

Iterator Buffer::getTailItr(){ // returns an iterator pointing the tail node in ll
    return Iterator(head->getPrev());
}

Iterator Buffer::getNextItr(Iterator it){ // returns an iterator of the next node pointed by it
    return (it + 1);
}

Iterator Buffer::getPrevItr(Iterator it){ // returns an iterator of the previous node pointed by it
    return (it - 1);
}

// prints out the ll like the following: contents of node, followed by a space,
// followed by -> followed by a space after list is printed, it skips a line
// ie has 2 endls, if list is empty, it prints "->" followed by 2 endls
void Buffer::print(){
    if(count == 0)
        std::cout << "->";
    else{
        Node *p = head;
        while (p != getTail()){
            std::cout << p->getWord() << " -> ";
            p = p->getNext();
        }
        std::cout << p->getWord();
    }
    std::cout << "\n\n";
}

// makes a deep copy of the ll for copy constructor and assignment operator "other" is copied
void Buffer::copy(const Buffer &other){
    clear();
    if (other.size() == 0)
        return;
    head = new Node(other[0]);
    count = 1;
    Node *p = other.head;
    unsigned i = 1;
    unsigned n = other.size();
    while(i < n){
        p = p->getNext();
        produceAtTail(p->getWord());
        i += 1;
    }
}

// clears the ll by deleting all nodes, calls the recursive function deleteBuffer()
void Buffer::clear(){
    deleteBuffer(head);
}

// recursively deletes the ll p, THIS FUNCTION MUST BE RECURSIVE
void Buffer::deleteBuffer(Node *p){
    if (count == 0 || p == NULL)
        return;
    else if (p->getNext() == p){
        delete p;
        count -= 1;
        return;
    }
    if (count >= 1){
        count -= 1;
        deleteBuffer(p->getNext());
    }
    delete p;
}

// non-member function, locates "str" in the range [first,last]
// if "str" is found in the range, return true, if "str" is not found, return false
bool findNode(Iterator first, Iterator last, std::string str){
    Iterator it;
    it = first;
    while(true){
        if (it.getCurr()->getWord() == str)
            return true;
        it += 1;
        if (it == last){
            if (it.getCurr()->getWord() == str)
                return true;
            break;
        }
    }
    return false;
}
