#ifndef Q_EQUATION_H
#define Q_EQUATION_H

#include <string>

class Q_equation {
        int m_a;
        int m_b;
        int m_c;
        float m_root_1;
        float m_root_2;
    public:
        int get_coefficient(string);
        Q_equation(int a = 1, int b = 1, int c = 1);
};


#endif