#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {

    public:

        Rational(int n = 1, int d = 1);
        int get_numerator();
        int get_denominator();
        void add(int n, int d);
        void sub(int n, int d);
        void mul(int n, int d);
        void div(int n, int d);

    private:

        void reduce();
        void clean_negatives();
        int m_numerator;
        int m_denominator;

};

#endif