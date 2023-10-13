// Constructors and destructors

class TestClass {

    public:

        // Constructors
        TestClass();
        TestClass(int a, int b);

        // Destructor
        ~TestClass();

    private:

        int m_a;
        int m_b;

        int * m_array;

};

TestClass::TestClass() : m_a(0), m_b(0) {

    m_array = new int[5];

}

TestClass::TestClass(int a, int b) : m_a(a), m_b(b) {

    m_array = new int[a + b];
    
}

TestClass::~TestClass() {

    delete[] m_array;

}

// If a member of a class is also a class, to initialize it in the constructor
// of the parent class, you should use member initialization (colon before the open
// bracket). If you don't do that, it's initialized using its default constructor.

int * p; // non-const pointer to non-const int. Both pointer value and value it points to can change
const int * p; // non-const pointer to const int. Pointer value can change but it cannot modify what it points to
int * const p; // const pointer to non-const int. Pointer value can't change but it can modify what it points to
const int * const p; // const pointer to const int. Neither pointer value nor value it points to can change.

// Void pointer is a pointer to data of no specific type. To dereference it, a pointer of a certain type must be assigned to it, and that pointer must be dereferenced.

/*
To review:
- Constructors and Destructors
- New and Delete
- Passing variables by reference, especially passing arrays by reference into function
- List of overloadable operators
*/

/*
"new"

int * foo;
foo = new (nothrow) int;
if (foo == nullptr) {
    // Take measures

}

"delete"
1.
int * foo;
foo = new int;
delete foo;

2. 
int * foo;
foo = new int[5];
delete[] foo;
*/