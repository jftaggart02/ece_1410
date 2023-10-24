#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"

template <typename T>
class Stack : public List<T> {

    public:

        Stack(); // Default constructor

        T top(void); // Returns value at top of stack

        void push(T); // Pushes value to top of stack

        T pop(void); // Returns the value popped from top of stack
    
};

template <typename T>
Stack<T>::Stack() { // Default constructor

    // empty because List's constructor will automatically be called

}

template <typename T>
T Stack<T>::top(void) { // Returns value at top of stack

    // If the stack isn't empty
    if (this->head != nullptr) {

        return this->head->getData();

    }

    // If list is empty
    else {

        return 0;

    }

}

template <typename T>
void Stack<T>::push(T data) { // Pushes value to top of stack

    // Create new node
    Node<T> *new_node = new Node(data);

    // Make the new node point to head
    new_node->setNext(this->head);

    // Make the new node the new head
    this->head = new_node;

}

template <typename T>
T Stack<T>::pop(void) { // Returns the value popped from top of stack

    // As long as the list isn't empty
    if (this->head != nullptr) {

        // Create a pointer to the head node
        Node<T> *node_to_pop = this->head;

        // Move head to the next node
        this->head = this->head->getNext();

        // Store data from "node_to_pop" to be returned later
        T data = node_to_pop->getData();

        // Delete the node we want to pop
        delete node_to_pop;

        // Return its data
        return data;

    }

    // If list is empty
    else {

        return 0;

    }
    
}

#endif // STACK_HPP