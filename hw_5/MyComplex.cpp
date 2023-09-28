#include "MyComplex.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Constructor with no arguments creates complex number with value 0 + 0i
MyComplex::MyComplex() {

    m_real = 0;

    m_imaginary = 0;

}

// Constructor with arguments initializes complex number with specified values
MyComplex::MyComplex(float rp, float ip) {

    m_real = rp;

    m_imaginary = ip;

}

// Returns complex number in string form with 1 digit after decimal point
string MyComplex::printMyComplex() {

    string result;
    stringstream result_stream;

    // Set precision of floats to one digit after decimal point
    result_stream << fixed << setprecision(1);

    // If imaginary part is negative,
    if (m_imaginary < 0) {

        // Use minus sign between real and imaginary parts
        result_stream << m_real << " - " << (-1 * m_imaginary) << "i"; 

    }
    // If imaginary part is positive,
    else {

        // Use plus sign between real and imaginary parts
        result_stream << m_real << " + " << m_imaginary << "i"; 

    }
    
    result = result_stream.str();
    return result;

}

// Define plus operation on MyComplex objects
MyComplex MyComplex::operator+(MyComplex right_side) {

    MyComplex sum;

    // Add real and imaginary components together 

    sum.m_real = this->m_real + right_side.m_real;

    sum.m_imaginary = this->m_imaginary + right_side.m_imaginary;

    return sum;

}

// Define minus operation on MyComplex objects
MyComplex MyComplex::operator-(MyComplex right_side) {

    MyComplex result;

    // Subtract real and imaginary components from each other

    result.m_real = this->m_real - right_side.m_real;

    result.m_imaginary = this->m_imaginary - right_side.m_imaginary;

    return result;

}

// Define multiply operation on MyComplex objects
MyComplex MyComplex::operator*(MyComplex right_side) {

    MyComplex result;

    float a = this->m_real,
        b = this->m_imaginary,
        c = right_side.m_real,
        d = right_side.m_imaginary;

    // Multiply the complex numbers using this formula

    result.m_real = a*c - b*d;
    result.m_imaginary = a*d + b*c;

    return result;

}

// Define divide operation on MyComplex objects
MyComplex MyComplex::operator/(MyComplex right_side) {

    MyComplex result;

    float a = this->m_real,
        b = this->m_imaginary,
        c = right_side.m_real,
        d = right_side.m_imaginary;

    // Divide the complex numbers using this formula

    result.m_real = (a*c + b*d) / (c*c + d*d);
    result.m_imaginary = (b*c - a*d) / (c*c + d*d);

    return result;

}