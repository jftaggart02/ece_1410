#include <q_equation.h>
#include <string>
#include <cmath>

Q_equation::Q_equation(int a, int b, int c) {
    // Convert coefficients to floats
    float a = m_a;
    float b = m_b;
    float c = m_c;
    // Compute roots and store values in class attributes
    m_root_1 = ( -b + sqrt(b*b - 4*a*c) ) / 2*a;
    m_root_2 = ( -b - sqrt(b*b - 4*a*c) ) / 2*a;
}

int Q_equation::get_coefficient(string which_one) {
    if (which_one.compare("a") == 0 || which_one.compare("A") == 0)
        return m_a;
    if (which_one.compare("b") == 0 || which_one.compare("B") == 0)
        return m_b;
    if (which_one.compare("c") == 0 || which_one.compare("C") == 0)
        return m_c;
}
