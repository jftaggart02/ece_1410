/*
Procedure:

1. Open input and output files.

2. Count every occurrance of each capital and lowercase letter in the input file. 
Store data in struct array.
    Note: Struct array should have:
        1. Letter
        2. # Occurrences
        3. % of total letters
    Note: I'll need to count number of total letters.
    
3. Print struct data to output file.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct letter {
    char letter;
    int occurrances;
    float percent;
};

void openFile(ifstream &, ofstream &);

void count(ifstream &, struct letter[]);

int main(int argc, char *argv[])
{

    ifstream infile;
    ofstream outfile;

    // Open input and output file streams.
    openFile(infile, outfile);



    return 0;

}

void openFile(ifstream &ifile, ofstream &ofile) {

    string if_name, of_name;

    // Ask for names of input and output files to open.
    cout << "Please enter name of input file: ";
    cin >> if_name;
    cout << "Please enter name of output file: ";
    cin >> of_name;

    // Open input and output files.
    ifile.open(if_name, ifstream::in);
    ofile.open(of_name, ofstream::out);

    // Check for errors.
    if (!ifile.is_open())
        cout << "Error opening file " << if_name << "." << endl;
        exit(EXIT_FAILURE);
    if (!ofile.is_open())
        cout << "Error opening file " << of_name << "." << endl;
        exit(EXIT_FAILURE);
    
}

void count(ifstream &ifile, struct letter letters[])
{



}