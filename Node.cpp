#include "Node.h"

template <class T>
Node<T>::~Node() {
    Node<T>* current = this;
    while (current->prev != nullptr) {
        current = current->prev;
    }
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}