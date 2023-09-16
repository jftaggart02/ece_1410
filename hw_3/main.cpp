#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
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

    // Set precision of output
    cout << fixed << setprecision(4);

    // While there's stuff in the file to read
    while (!ifile.eof()) {

        // Read 3 integers
        ifile >> ai;
        ifile >> bi;
        ifile >> ci;

        // Add to output string
        cout << ai << "\t" << bi << "\t" << ci << "\t";

        // Convert to floats for calculation
        a = ai;
        b = bi;
        c = ci;

        // Check for a = 0 (can't divide by 0)
        if (ai == 0) {

            // Debugging:
            cout << "cannot divide by 0" << endl;

        }
        
        // Check for complex roots
        else if ( (b*b - 4*a*c) < 0 ) {

            // Debugging:
            cout << "complex roots, did not compute" << endl;

        }

        // If all is well
        else {

            // Calculate roots
            root1 = ( -b + sqrt(b*b - 4*a*c) ) / (2*a);
            root2 = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);

            // Add to output string
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

    // Set output precision
    ofile << fixed << setprecision(4);

    // While there's stuff in the file to read
    while (!ifile.eof()) {

        // Read 3 integers
        ifile >> ai;
        ifile >> bi;
        ifile >> ci;

        // Add to output string
        ofile << ai << "\t" << bi << "\t" << ci << "\t";

        // Convert to floats for calculation
        a = ai;
        b = bi;
        c = ci;

        // Check for a = 0 (can't divide by 0)
        if (ai == 0) {

            // Add error message to output string
            ofile << "cannot divide by 0" << endl;

        }
        
        // Check for complex roots
        else if ( (b*b - 4*a*c) < 0 ) {
            
            // Add error message to output string
            ofile << "complex roots, did not compute" << endl;

        }

        // If all is well
        else {

            // Calculate roots
            root1 = ( -b + sqrt(b*b - 4*a*c) ) / (2*a);
            root2 = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);

            // Add to output string
            ofile << root1 << "\t" << root2 << endl;

        }

    }

}