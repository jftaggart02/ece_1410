#include "rational.h"
#include <iostream>
#include <string>
#define EXIT_SUCCESS 0

using namespace std;

int main() {

    int numerator;
    int denominator;

    // Ask for initial numerator and denominator
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    // Check for illegal input?

    // Instantiate Rational object
    Rational fraction(numerator, denominator);

    // Print reduced fraction
    cout << "Fraction reduces to " 
    << fraction.get_numerator() << "/" << fraction.get_denominator()
    << endl;

    // Enter menu-driven loop
    while (true) {

        // Print options
        cout << endl 
        << "1. Add a rational" << endl
        << "2. Subtract a rational" << endl
        << "3. Multiply by a rational" << endl
        << "4. Divide by a rational" << endl
        << "0. Exit" << endl;

        // Ask for selection
        int selection;
        cout << "Enter selection: ";
        cin >> selection;

        // Check for illegal selection
        try {
            if (selection < 0 || selection > 4) {

                throw string("Invalid selection! Please try again.");

            }
        }
        catch (string err_msg) {

            cerr << "Error: " << err_msg << endl;

            // Re-start loop
            continue;

        }

        // Exit if selection was 0
        if (selection == 0) {
            exit(EXIT_SUCCESS);
        }

        // Ask for fraction input
        int operator_n;
        int operator_d;

        cout << "Enter numerator: ";
        cin >> operator_n;
        cout << "Enter denominator: ";
        cin >> operator_d;

        // Check for illegal fraction input?

        // Perform selected operation
        switch (selection) {

            case 1:
                fraction.add(operator_n, operator_d);
                break;
            case 2:
                fraction.sub(operator_n, operator_d);
                break;
            case 3:
                fraction.mul(operator_n, operator_d);
                break;
            case 4:
                fraction.div(operator_n, operator_d);
                break;

        }

        // Print result
        cout << fraction.get_numerator() << "/" << fraction.get_denominator() << endl;

    }

    return 0;
}