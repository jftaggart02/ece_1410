#ifndef LIST_HPP
#define LIST_HPP

#include <sstream>

using namespace std;

template <typename T>
class List {

    public:

        List(void); // Default constructor

        void insert(T); // Insert at Tail

        T at(int); // Returns the value stored at a given list index

        int count(void); // Returns the number of nodes in the list

        bool contains(T); // Returns true if the list contains given value. False otherwise

        bool remove(T); // Remove the node with the given value

        string toString(void); // Converts each node value to a string and 
            // concatenates them into a string with spaces between the values

        void reset(void); // Deletes all nodes

    private:

        Node<T> *head; // Points to the head node
        // Node<T> *tail; // Points to the tail node

        // void setHead(Node<T> *); // Sets head
        // void setTail(Node<T> *); // Sets tail

};

// template <typename T>
// void setHead(Node<T> *new_head) { // Sets head

//     this->head = new_head;

// } 

// template <typename T>
// void setTail(Node<T> *new_tail) { // Sets tail

//     this->tail = new_tail;

// }

template <typename T>
List<T>::List(void) { // Default constructor

    this->head = nullptr;
    // this->tail = nullptr;

}

/* USING TAIL POINTER
template <typename T>
void insert(T data) { // Insert at Tail

    // Create node with given value. Pointer of that node is null.
    Node *new_node = new Node(data);
    new_node->setNext(nullptr);

    // If head and tail point to null (empty case), make both head and tail
        // point to new node
    if (this->head == nullptr && this->tail == nullptr) {

        this->head = new_node;
        this->tail = new_node;

    }

    // Otherwise, 
    else {

        // Have the tail node point to the new node
        this->tail->setNext(new_node);

        // Then, make tail point to the new node
        this->tail = this->tail->getNext();

    }

}
*/

template <typename T>
void List<T>::insert(T data) { // Insert at Tail

    // Create node with given value. Pointer of that node is null.
    Node<T> *new_node = new Node(data);
    new_node->setNext(nullptr);

    // If the list is empty
    if (this->head == nullptr) {

        // Make the new node the head node
        this->head = new_node;

    }

    else {

        // Set current node to the beginning (head node)
        Node<T> *current = this->head;

        // Move through the list until we reach the end
        while (current->getNext() != nullptr) {

            current = current->getNext();

        }

        // Make the last node point to the new node
        current->setNext(new_node);

    }

}

template <typename T>
T List<T>::at(int index) { // Returns the value stored at a given list index

    // If our list is not empty
    if (this->head != nullptr) {

       // Set current node to the beginning (head node)
        Node<T> *current = this->head;

        // If we want the first node,
        if (index == 0) {

            // Return the data of the current node
            return current->getData();

        }

        else {

            // Move up the list "index" times
            for (int i = 0; i < index; i++) {

                current = current->getNext();

            }

            // Return the data of the current node
            return current->getData();

        }

    }

}

template <typename T>
int List<T>::count(void) { // Returns the number of nodes in the list

    // Set current node to the beginning (head node)
    Node<T> *current = this->head;

    // If our list is empty, return 0
    if (current == nullptr) {

        return 0;

    }

    // If we got to this point, we have at least 1 node
    int num_nodes = 1;

    // While there are more nodes in the list
    while (current->getNext() != nullptr) {

        // Move to the next node
        current = current->getNext();

        // Increment node count
        num_nodes++;

    }

    return num_nodes;

}

template <typename T>
bool List<T>::contains(T data) { // Returns true if the list contains given value. False otherwise 

    // If our list is empty,
    if (this->head == nullptr) {

        // The list doesn't contain a node with the given value
        return false;

    }

    // Set current node to the beginning (head node)
    Node<T> *current = this->head;

    // While we haven't found a node with given data,
    while (current->getData() != data) {

        // If we haven't yet reached the end of the list,
        if (current->getNext() != nullptr) {

            // Move up the list
            current = current->getNext();

        }

        else {

            // The list doesn't contain a node with the given data
            return false;

        }

    }

    // If we made it to this point, we found a node with the given data
    return true;

}

template <typename T>
bool List<T>::remove(T value) { // Remove the node with the given value 

    // If the list contains a node with the given value
    if (this->contains(value)) {

        // Set current and previous node to the beginning (head node)
        Node<T> *current = this->head;
        Node<T> *previous = this->head;

        // Move up the list until we reach the first node with the given value
        if (current->getData() != value) {

            current = current->getNext();

        }

        while (current->getData() != value) {

            previous = current;
            current = current->getNext();
            
        }

        // Remove the current node
        // beginning case (current == head)
        if (current == this->head) {

            this->head = current->getNext();
            delete current;

        }

        // middle or end case (else)
        else {

            previous->setNext(current->getNext());
            delete current;

        }

        // We successfully removed a node with the given value
        return true;

    }

    else {

        // We can't remove a node we don't have
        return false;

    }

}

template <typename T>
string List<T>::toString(void) { // Converts each node value to a string and 
                        // concatenates them into a string with spaces between the values 
            
    stringstream output_string("");

    // empty list case
    if (this->head == nullptr) {

        return "";

    }

    // Set current node to the beginning (head node)
    Node<T> *current = this->head;

    // Add the data from each node to the stringstream
    while (true) {

        output_string << current->getData() << " ";

        if (current->getNext() == nullptr) {

            break;

        }

        else {

            current = current->getNext();

        }

    }

    // Return the data in the stringstream
    return output_string.str();

}

template <typename T>
void List<T>::reset(void) { // Deletes all nodes

    Node<T> *cursor = this->head;

    // Until the list is empty
    while (this->head != nullptr) {

        // Set cursor to head
        cursor = this->head;

        // Set head to next
        head = head->getNext();

        // Delete what the cursor is pointing to
        delete cursor;

    }

}

#endif // LIST_HPP