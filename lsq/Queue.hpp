#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue : public Stack<T> {

    public:

        Queue(); // Default constructor

        void enqueue(T); // Pushes node with given value to back of queue
        // Same as insert from list

        T dequeue(void); // Returns value at front of queue and dequeues it
        // Same as pop from Stack.hpp

        T front(void); // Returns value at front of queue
        // Same as top from stack.hpp

};

template <typename T>
Queue<T>::Queue() {

    // Empty because List's constructor will automatically be called.

}

template <typename T>
void Queue<T>::enqueue(T data) {    // Pushes node with given value to back of queue
                                    // Same as insert from list

    this->insert(data);

}

template <typename T>
T Queue<T>::dequeue(void) {     // Returns value at front of queue and dequeues it
                                // Same as pop from Stack.hpp

    return this->pop();

}

template <typename T>
T Queue<T>::front(void) {       // Returns value at front of queue
                                // Same as top from stack.hpp

    return this->top();

}

#endif // QUEUE_HPP