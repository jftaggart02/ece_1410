#include <iostream>

using namespace std;

class Vector {

        int m_a;
        int m_b;

    public:

        Vector();
        Vector(int, int);
        Vector operator+(int);
        Vector operator+(Vector*);
        void display_values();

};

Vector::Vector() : m_a(0), m_b(0) {

}

Vector::Vector(int a, int b) : m_a(a), m_b(b) {

}

Vector Vector::operator+(int scalar) {
    Vector john_cena(m_a, m_b);
    john_cena.m_a += scalar;
    john_cena.m_b += scalar;
    return john_cena;
}

Vector Vector::operator+(Vector * right_side) {
    Vector john_cena(m_a, m_b);
    john_cena.m_a += right_side->m_a;
    john_cena.m_b += right_side->m_b;
    return john_cena;
}

void Vector::display_values() {
    cout << "A: " << m_a;
    cout << ", B: " << m_b;
    cout << "." << endl;
}

int main() {

    // Vector test_vectors[2] = {{2, 4}, {3, 6}};
    Vector test_vector_a(3, 4);
    Vector test_vector_b(4, 6);

    Vector test_vector_c = test_vector_a.operator+(&test_vector_b);
    Vector test_vector_d = test_vector_a + 4;

    test_vector_c.display_values();
    test_vector_d.display_values();

    return 0;
}