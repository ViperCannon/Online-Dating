#ifndef HW5_NODE_H
#define HW5_NODE_H

template <class T>
class Node {
    ~Node();
public:
    T value;
    Node* next;
    Node* prev;

private:

};

#endif //HW5_NODE_H