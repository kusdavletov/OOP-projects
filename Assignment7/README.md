## Description
In this project, we had deal with buffer, which is implemented as a circular doubly-linked list (LL or ll) and an iterator to traverse the LL.

Circular doubly-linked list – a linked list is a data structure that can grow and shrink dynamically and allows direct access to elements using indexing. In a circular doubly linked list, each node contains two pointers: one to the next node in the list, and the other to the previous node in the list. Moreover, the last node points back to the first node in the list, not to NULL, as the next node, and the first node points back to the last node in the list, not to NULL, as the previous node.

Iterator – a pointer-like object that accesses the elements in a circular doubly-linked list. The buffer class supports two major operations of produce and consume. For a produce operation, a node is created and added to the linked list, while for a consume operation, a node is deleted from the list.

In this project, we use 3 classes: Node, Buffer, Iterator.
