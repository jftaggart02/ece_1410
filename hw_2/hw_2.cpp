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

#include <iostream> // For cin and cout
#include <fstream> // For reading and writing to files
#include <string> // For string functionality
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iomanip> // For setting output float precision
#include <cstdio> // For EOF macro

#define ALPHABET_SIZE 26

using namespace std;

struct letter {
    char letter;
    int occurrances;
    float percent;
};

// Function prototypes
void openFile(ifstream &, ofstream &);
void count(ifstream &, struct letter[]);
void printResult(ofstream &, struct letter[]);
bool is_letter(char);
void initialize_letter_array(struct letter[]);

int main()
{

    ifstream infile;
    ofstream outfile;

    // Create array of letter structs
    struct letter letter_array[ALPHABET_SIZE*2];

    // Initialize array of letter structs with all the upper and lowercase letters and 0 values
    initialize_letter_array(letter_array);

    // Open input and output file streams.
    openFile(infile, outfile);

    // Count number of each letter and store related data in struct
    count(infile, letter_array);

    // Print data from structure to output file
    printResult(outfile, letter_array);

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
    ifile.open(if_name);
    ofile.open(of_name);

    // Check for errors.
    if (!ifile.is_open()) {
        cout << "Error opening file \"" << if_name << "\"." << endl;
        exit(EXIT_FAILURE);
    }
    if (!ofile.is_open()) {
        cout << "Error opening file " << of_name << "." << endl;
        exit(EXIT_FAILURE);
    }
    
}

void count(ifstream &ifile, struct letter letters[])
{

    char char_read;

    int letter_count = 0;

    // Until end of file is reached, count each letter
    // and update array of structs accordingly.
    while (ifile.get(char_read)) {

        // For debugging:
        // cout << char_read << endl;

        // If character read is a letter
        if (is_letter(char_read)) {

            // Increase total letter count
            letter_count++;

            // Loop through struct array until we reach correct entry
            int i;
            for (i = 0; letters[i].letter != char_read; i++);
            
            // Increase count of that letter
            letters[i].occurrances++;

        }

    }

    // Loop through array and update percentages now that letter_count is finalized.
    for (int i = 0; i < ALPHABET_SIZE*2; i++) {
        letters[i].percent = ( (float) letters[i].occurrances / (float) letter_count ) * 100.0f;
    }

}

void printResult(ofstream &ofile, struct letter letters[]) {

    for (int i = 0; i < ALPHABET_SIZE*2; i++) {

        // Set float precision to 2 decimal places
        ofile << fixed << setprecision(2);

        // Print data stored in struct array
        ofile << letters[i].letter << " "
              << letters[i].occurrances << " "
              << letters[i].percent << "%"
              << endl;

    }

}

bool is_letter(char letter) {

    if ((letter >= 'A' && letter <= 'Z')||(letter >= 'a' && letter <= 'z'))
        return true;
    else
        return false;

}

void initialize_letter_array(struct letter letter_array[]) {

    // Initialize uppercase
    for (int i = 0; i < ALPHABET_SIZE; i++) {

        letter_array[i].letter = (char) i + 'A';
        letter_array[i].occurrances = 0;
        letter_array[i].percent = 0.0;

    }

    // Initialize lowercase
    for (int i = ALPHABET_SIZE; i < ALPHABET_SIZE*2; i++) {

        letter_array[i].letter = (char) i + 'a' - (char) ALPHABET_SIZE;
        letter_array[i].occurrances = 0;
        letter_array[i].percent = 0.0;

    }

}

