#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <string>

using namespace std;

class MyComplex {

    public:

        MyComplex();

        MyComplex(float rp, float ip);

        string printMyComplex();

        MyComplex operator+(MyComplex right_side);

        MyComplex operator-(MyComplex right_side);

        MyComplex operator*(MyComplex right_side);

        MyComplex operator/(MyComplex right_side);

    private:

        float m_real;

        float m_imaginary;

};

#endif