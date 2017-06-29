#include "Iterator.h"
#include <iostream>

Iterator::Iterator(Node *currIn){ // initializes curr to currIn
    curr = currIn;
}

const std::string Iterator::operator*() const{ // dereference curr, returns plain text string
    return curr->getWord();
}

Iterator& Iterator::operator++(){ // pre-increment operator
    curr = curr->getNext();
    return *this;
}

Iterator Iterator::operator++(int){ // post-increment operator
    Iterator temp = *this;
    temp.curr = temp.curr->getNext();
    return temp;
}

Iterator Iterator::operator+(const int &a){ // for iterator math - for example it = it + 2;
    Iterator temp = *this;
    for (int i = 1; i <= a; i++)
        temp.curr = temp.curr->getNext();
    return temp;
}

Iterator Iterator::operator+=(const int &a){ // for iterator math - for example it += 2;
    for (int i = 1; i <= a; i++)
        curr = curr->getNext();
    return *this;
}

Iterator& Iterator::operator--(){ // pre-decrement operator
    curr = curr->getPrev();
    return *this;
}

Iterator Iterator::operator--(int a){ // post-decrement operator
    Iterator temp = *this;
    temp.curr = temp.curr->getPrev();
    return temp;
}

Iterator Iterator::operator-(const int &a){ // for iterator math - for example it = it - 2;
    Iterator temp = *this;
    for (int i = 1; i <= a; i++)
        temp.curr = temp.curr->getPrev();
    return temp;
}

Iterator Iterator::operator-=(const int &a){ // for iterator math - for example it -= 2;
    for (int i = 1; i <= a; i++)
        curr = curr->getPrev();
    return *this;
}

bool Iterator::operator==(const Iterator &other){ // equality operator - is true if 2 iterators are pointing to the same node
    if (curr == other.curr)
        return true;
    else
        return false;
}

bool Iterator::operator!=(const Iterator &other){ // inequality operator - is true if 2 iterators are pointing to different nodes
    if (curr != other.curr)
        return true;
    else
        return false;
}

Node*& Iterator::getCurr(){ // returns the node to which the iterator points
    return curr;
}
