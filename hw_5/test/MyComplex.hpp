#include "MyComplex.h"

MyComplex::MyComplex() {

    m_real = 0;

    m_imaginary = 0;

}

MyComplex::MyComplex(float rp, float ip) {

    m_real = rp;

    m_imaginary = ip;

}

string MyComplex::printMyComplex() {

    string result;

    result += to_string(m_real);
    result += " + ";
    result += to_string(m_imaginary);
    result += "i";

    return result;

}

MyComplex MyComplex::operator+(MyComplex right_side) {

    MyComplex sum;

    sum.m_real = this->m_real + right_side.m_real;

    sum.m_imaginary = this->m_imaginary + right_side.m_imaginary;

    return sum;

}

MyComplex MyComplex::operator-(MyComplex right_side) {

    MyComplex result;

    result.m_real = this->m_real - right_side.m_real;

    result.m_imaginary = this->m_imaginary - right_side.m_imaginary;

    return result;

}

MyComplex MyComplex::operator*(MyComplex right_side) {

    MyComplex result;

    float a = this->m_real,
        b = this->m_imaginary,
        c = right_side.m_real,
        d = right_side.m_imaginary;

    result.m_real = a*c - b*d;
    result.m_imaginary = a*d + b*c;

    return result;

}

MyComplex MyComplex::operator/(MyComplex right_side) {

    MyComplex result;

    float a = this->m_real,
        b = this->m_imaginary,
        c = right_side.m_real,
        d = right_side.m_imaginary;

    result.m_real = (a*c + b*d) / (c*c + d*d);
    result.m_imaginary = (b*c - a*d) / (c*c + d*d);

    return result;

}