// Your TASK: Declare and Implement templated BST class that passes all tests
#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

#include <sstream>

#define DEBUG 0

using namespace std;

template <typename T>
class BST {
private:
    Node<T> *root;
    int node_count;
public:
    // Constructor
    BST();

    // Insert
    void insert(T data);

    // Contains
    bool contains(T data);

    // Search
    string search(T data);

    // Count
    int count();

    // Remove (Optional)
    void remove(T data) {}
};

/*
template <typename T>
BST<T>::() {

    

}
*/

template <typename T>
BST<T>::BST() {

    this->root = nullptr;
    this->node_count = 0;

}

template <typename T>
void BST<T>::insert(T data) {

    #if DEBUG
    cout << "inserting " << data << endl;
    #endif

    // Case 1: Empty Tree (root points to null)
    if (this->root == nullptr) {

        #if DEBUG
        cout << "empty tree\n";
        #endif

        this->root = new Node<T>(data);

    }

    // Case 2: Non-empty Tree
    else {

        #if DEBUG
        cout << "not empty tree\n";
        #endif

        // Start at root.
        Node<T> *current = this->root;

        /*
        If data is greater than or equal to value of current node, look at right child
            If right child is null, create new node with data and have right child point to it
            Else, move to right child and repeat function
        Else, look at left child
            If left child is null, create new node with data and have left child point to it
            Else, move to left child and repeat function
        */

        while (true) {

            if (data >= current->getData()) {

                #if DEBUG
                cout << "data is greater than current node\n";
                #endif

                if (current->getRight() == nullptr) {

                    #if DEBUG
                    cout << "there is no right child\n";
                    #endif

                    current->setRight(new Node<T>(data));
                    break; // Break out of loop

                }

                else {

                    #if DEBUG
                    cout << "there is a right child, so lets go to it\n";
                    #endif

                    current = current->getRight();

                }

            }

            else {

                #if DEBUG
                cout << "data is less than current node\n";
                #endif

                if (current->getLeft() == nullptr) {

                    #if DEBUG
                    cout << "there is no left child\n";
                    #endif

                    current->setLeft(new Node<T>(data));
                    break; // Break out of loop

                }

                else {

                    #if DEBUG
                    cout << "there is a left child, so lets go to it\n";
                    #endif

                    current = current->getLeft();

                }

            }

        }

    }

    // Increment node_count by 1
    this->node_count++;

}

template <typename T>
int BST<T>::count() {

    return this->node_count;

}

template <typename T>
bool BST<T>::contains(T data) {

    #if DEBUG
    cout << "does bst contain " << data << "?\n";
    #endif

    /*
    Loop
        If we're pointing to nullptr,
            return false
        
        Else, Compare data with current node data. 
            If equal, return true.  
            Else,
                If data is greater than current node data,
                    move to right child
                Else,
                    move to left child
    */

    Node<T> *current = this->root;

    while (true) {

        if (current == nullptr) {

            #if DEBUG
            cout << "it doesn't\n";
            #endif

            return false;
        }

        else if (data == current->getData()) {

            #if DEBUG
            cout << "it does\n";
            #endif

            return true;
        }

        else {

            if (data > current->getData()) {

                #if DEBUG
                cout << "not sure, let's go right\n";
                #endif    

                current = current->getRight();

            }

            else {

                #if DEBUG
                cout << "not sure, let's go left\n";
                #endif   

                current = current->getLeft();

            }

        }

    }

    // If we somehow got to the end without triggering the return statements,
    // something went wrong.
    return false;

}

template <typename T>
string BST<T>::search(T data) {

    #if DEBUG
    cout << "Searching tree for " << data << endl;
    #endif   

    /*
    If root is null, return "Not found: "
    If root isn't null, add "root(data)" to stringstream 

    Loop
        If we're pointing to nullptr,
            return "Not found: " plus stringstream
        
        Else, Compare data with current node data. 
            If equal, return "Found: " plus stringstream.  
            Else,
                If data is greater than current node data,
                    add ->right(data) to stringstream
                    move to right child
                Else,
                    add ->left(data) to stringstream
                    move to left child
    */

    Node<T> *current = this->root;

    stringstream path_string("");

    if (current == nullptr) {

        #if DEBUG
        cout << "Empty tree\n";
        #endif   

        return "Not found: ";
    }

    else {

        #if DEBUG
        cout << "Not empty tree\n";
        #endif 

        path_string << "root(" << current->getData() << ")";
    }

    while (true) {

        if (current == nullptr) {

            #if DEBUG
            cout << "Not found\n";
            #endif 

            return "Not found: " + path_string.str();
        }

        else if (data == current->getData()) {

            #if DEBUG
            cout << "Found\n";
            #endif 

            return "Found: " + path_string.str();
        }

        else {

            if (data > current->getData()) {

                #if DEBUG
                cout << "Not sure. Let's go right\n";
                #endif 

                if (current ->getRight() != nullptr)
                    path_string << "->right(" << current->getRight()->getData() << ")";
                current = current->getRight();

            }

            else {

                #if DEBUG
                cout << "Not sure. Let's go left\n";
                #endif 

                if (current ->getLeft() != nullptr)
                    path_string << "->left(" << current->getLeft()->getData() << ")";
                current = current->getLeft();

            }

        }

    }

    // If we somehow got to the end without triggering the return statements,
    // something went wrong.
    return "Something went wrong";

}

#endif // BST_HPP