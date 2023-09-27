#include "rational.h"
#include <iostream>
#include <string>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;

int main() {

    float numerator_float;
    float denominator_float;

    start:

    // Ask for initial numerator and denominator
    cout << "Enter numerator: ";
    cin >> numerator_float;
    cout << "Enter denominator: ";
    cin >> denominator_float;

    int numerator = (int) numerator_float;
    int denominator = (int) denominator_float;

    // Check for illegal input
    try {

        if (denominator == 0) {

            throw string("Cannot divide by 0!");

        }
        else if (numerator == 0) {

            throw string("Fraction cannot be 0!");

        }

    }
    catch (string error_msg) {

        cerr << "Error: " << error_msg << std::endl;
        cout << "Please try again." << endl;
        goto start;

    }

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
        float selection_float;
        cout << "Enter selection: ";
        cin >> selection_float;

        int selection = (int) selection_float;

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
        float operator_n_float;
        float operator_d_float;

        cout << "Enter numerator: ";
        cin >> operator_n_float;
        cout << "Enter denominator: ";
        cin >> operator_d_float;

        int operator_n = (int) operator_n_float;
        int operator_d = (int) operator_d_float;

        // Check for illegal fraction input
        try {

            if (operator_d == 0) {

                throw string("Cannot divide by 0!");

            }
            else if (operator_n == 0) {

                throw string("Fraction cannot be 0!");

            }

        }
        catch (string error_msg) {

            cerr << "Error: " << error_msg << std::endl;
            cout << "Please try again." << endl;
            continue;

        }

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
        cout << "Result: "
        << fraction.get_numerator() << "/" << fraction.get_denominator() << endl;

    }

    return 0;
}