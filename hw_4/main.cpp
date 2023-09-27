#include "rational.h"
#include <iostream>
#include <string>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;

bool is_fraction_good(float numerator, float denominator);

bool is_selection_good(float selection);

int main() {

    float numerator_float;
    float denominator_float;

    start:

    // Ask for initial numerator and denominator
    cout << "Enter numerator: ";
    cin >> numerator_float;
    cout << "Enter denominator: ";
    cin >> denominator_float;

    // Check for illegal fraction input.
    if (!is_fraction_good(numerator_float, denominator_float)) {

        // Go to the beginning and ask for input again if invalid input is given
        goto start;

    }

    // Cast input to int to instantiate Rational class
    int numerator = (int) numerator_float;
    int denominator = (int) denominator_float;

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

        // Check for illegal selection
        if (!is_selection_good(selection_float)) {

            // If illegal selection was given, go back to the beginning of the loop.
            continue;

        }

        int selection = (int) selection_float;

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

        // Check for illegal fraction input
        if (!is_fraction_good(operator_n_float, operator_d_float)) {

            // If illegal input was given, go back to the beginning of the loop.
            continue;

        }

        // Cast to ints for fraction operations
        int operator_n = (int) operator_n_float;
        int operator_d = (int) operator_d_float;

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

bool is_fraction_good(float numerator, float denominator) {

    // 1. Check to see if fraction contains a float.
    try {

        float numerator_copy = numerator;

        // Chop off the digits after the decimal
        numerator_copy = (int) numerator_copy;

        // Compare numerator to int equivalent
        if (numerator_copy != numerator) {

            throw string("Error: input contains a floating-point number.");

        }

        float denominator_copy = denominator;

        // Chop off the digits after the decimal
        denominator_copy = (int) denominator_copy;

        if (denominator_copy != denominator) {

            throw string("Error: input contains a floating-point number.");

        }


    }
    catch (string err_msg) {

        cerr << err_msg << endl;
        return false; 

    }

    // 2. Check to see if either numerator or denominator is 0
    try {

        if ((int) numerator == 0) {

            throw string("Error: fraction cannot be 0.");

        }
        else if ((int) denominator == 0) {

            throw string("Error: cannot divide by 0.");

        }

    }
    catch (string err_msg) {

        cerr << err_msg << endl;
        return false;

    }

    return true;

}

bool is_selection_good(float selection) {

    // Check for floats
    try {

        float selection_copy = selection;

        // Chop off the digits after the decimal
        selection_copy = (int) selection_copy;

        // Compare numerator to int equivalent
        if (selection_copy != selection) {

            throw string("Error: input contains a floating-point number.");

        }

    }
    catch (string err_msg) {

        cerr << err_msg << endl;
        return false;

    }

    // Check for input out of the acceptible range.
    int selection_int = (int) selection;
    try {

        if (selection_int < 0 || selection_int > 4) {

            throw string("Error: invalid selection.");

        }

    }
    catch (string err_msg) {

        cerr << err_msg << endl;
        return false;

    }

    return true;

}