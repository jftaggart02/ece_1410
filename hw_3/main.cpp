#include <fstream> // For reading and writing to files
#include <iostream> // For printing to screen
#include <string> // For use of strings
#include <cmath> // For sqrt()
#include <iomanip> // For setting cout floating-point precision
#define EXIT_FAILURE 1

using namespace std;

void open_file(fstream &file, string file_name);
void compute_roots(fstream &ifile);
void compute_roots(fstream &ifile, fstream &ofile);

int main(int argc, char *argv[]) {
    
    bool output_file = false;

    // Check for correct number of command-line parameters.
    if (argc == 2) {
        output_file = false;
    }
    else if (argc == 3) {
        output_file = true;
    } 
    else {
        cout << "Invalid command line parameters." << endl;
        cout << "Must have the form \"./hw3 [input file]\" or \"./hw3 [input file] [output file]" << endl;
        exit(EXIT_FAILURE);
    }

    // Open input file, and open output file if applicable
    fstream infile;
    fstream outfile;

    // If output file given on command line,
    if (output_file) {

        // Open both files
        open_file(infile, argv[1]);
        open_file(outfile, argv[2]);

        // Read input file, compute roots, and print to output file
        compute_roots(infile, outfile);

    }
    else {

        // Open just input file
        open_file(infile, argv[1]);

        // Read input file, compute roots, and print to console
        compute_roots(infile);

    }

    return 0;
}

void open_file(fstream &file, string file_name) {

    // Open file
    file.open(file_name);

    // Check for errors opening file.
    if (!file.is_open()) {
        cout << "Problem opening file " << file_name << endl;
        exit(EXIT_FAILURE);
    }

}

void compute_roots(fstream &ifile) {

    // Coefficients for quadratic equation
    int ai, bi, ci;

    // Float versions
    float a, b, c;

    // Roots of quadratic equation
    float root1, root2;

    // Set precision of floats printed
    cout << fixed << setprecision(4);

    // While there's stuff in the input file to read, read 1st integer
    while (ifile >> ai) {

        // Read the other 2 integers
        ifile >> bi;
        ifile >> ci;

        // Print those to console
        cout << ai << "\t" << bi << "\t" << ci << "\t";

        // Convert to floats for calculation
        a = ai;
        b = bi;
        c = ci;

        // Check for a = 0 (can't divide by 0)
        if (ai == 0) {

            cout << "cannot divide by 0" << endl;

        }
        
        // Check for complex roots
        else if ( (b*b - 4*a*c) < 0 ) {

            cout << "complex roots, did not compute" << endl;

        }

        // If all is well
        else {

            // Calculate roots
            root1 = ( -b + sqrt(b*b - 4*a*c) ) / (2*a);
            root2 = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);

            // Print roots to console
            cout << root1 << "\t" << root2 << endl;

        }

    }

}

void compute_roots(fstream &ifile, fstream &ofile) {

    // Coefficients for quadratic equation
    int ai, bi, ci;

    // Float versions
    float a, b, c;

    // Roots of quadratic equation
    float root1, root2;

    // Set precision of floats written to file
    ofile << fixed << setprecision(4);

    // While there's stuff in the input file to read, read first integer
    while (ifile >> ai) {

        // Read the other 2 integers
        ifile >> bi;
        ifile >> ci;

        // Write them to output file
        ofile << ai << "\t" << bi << "\t" << ci << "\t";

        // Convert to floats for calculation
        a = ai;
        b = bi;
        c = ci;

        // Check for a = 0 (can't divide by 0)
        if (ai == 0) {

            ofile << "cannot divide by 0" << endl;

        }
        
        // Check for complex roots
        else if ( (b*b - 4*a*c) < 0 ) {
            
            ofile << "complex roots, did not compute" << endl;

        }

        // If all is well
        else {

            // Calculate roots
            root1 = ( -b + sqrt(b*b - 4*a*c) ) / (2*a);
            root2 = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);

            // Write to output file
            ofile << root1 << "\t" << root2 << endl;

        }

    }

}