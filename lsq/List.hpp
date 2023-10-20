#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {

    public:

        List(void); // Default constructor

        void insert(T); // Insert at Tail

        T at(int); // Returns the value stored at a given list index

        int count(void); // Returns the number of nodes in the list

        bool contains(T); // Returns true if the list contains given value. False otherwise

        void remove(T); // Remove the node with the given value

        string toString(void); // Converts each node value to a string and 
            // concatenates them into a string with spaces between the values

        void reset(void); // Deletes all nodes

    private:

        Node<T> *head; // Points to the head node
        Node<T> *tail; // Points to the tail node

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
    this->tail = nullptr;

}

template <typename T>
void insert(T data) { // Insert at Tail

    // Create node with given value. Pointer of that node is null.
    Node new_node(data);
    new_node.setNext(nullptr);

    // If head and tail point to null (empty case), make both head and tail
        // point to new node
    if (this->head == nullptr && this->tail == nullptr) {

        this->head = &new_node;
        this->tail = &new_node;

    }

    // Otherwise, 
    else {

        // Have the tail node point to the new node
        this->tail->setNext(&new_node);

        // Then, make tail point to the new node
        this->tail = this->tail->getNext();

    }

}

template <typename T>
T at(int index) { // Returns the value stored at a given list index

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

            current->setNext(current->getNext());

        }

        // Return the data of the current node
        return current->getData();

    }

}

template <typename T>
int count(void) { // Returns the number of nodes in the list

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
        current->setNext(current->getNext());

        // Increment node count
        num_nodes++;

    }

    return num_nodes;

}


#endif // LIST_HPP