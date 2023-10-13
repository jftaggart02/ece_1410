#include <iostream>

using namespace std;

void change_values(int* a, int& b) {
    *a = a + b;
    b = *a;
}

int main() {

    int first = 10;
    int second = 20;

    change_values(&first, second);

    cout << first << " " << second;

    return 0;
}