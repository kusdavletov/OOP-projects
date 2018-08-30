#include "Node.h"
#include <iostream>

Node::Node(){ // default constructor
    next = NULL;
    prev = NULL;
    word.clear();
}

Node::Node(std::string data){ // constructor with single argument
    next = this;
    prev = this;
    word = data;
}

Node::Node(std::string data, Node *value){ // constructor with 2 arguments (second argument is a pointer to prev node) primary constructor
    next = value->next;
    value->next = this;
    prev = value;
    word = data;
    if (value->prev == value){
        value->prev = this;
    }
}

std::string& Node::getWord(){ // accessor for word - returns contents of word
    return word;
}

Node* Node::getNext() const{  // accessor for next - returns pointer to node to which next is pointing
    return next;
}

Node* Node::getPrev() const{  // accessor for next - returns pointer to node to which prev is pointing
    return prev;
}

void Node::setWord(std::string data){  // mutator for word - changes string to value passed in
    word = data;
}

void Node::setNext(Node *value){     // mutator for next - changes pointer to value passed in
    next = value;
}

void Node::setPrev(Node *value){ // mutator for prev - changes pointer to value passed in
    prev = value;
}
